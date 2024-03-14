{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

module Main (main) where
import System.Environment

calcpos :: Int -> Int -> Int -> Int -> Int
calcpos rule lastElem actualElem nextElem =
  rule `div` (2^(4*lastElem + 2*actualElem + nextElem)) `mod` 2

getActualCell :: String -> Int -> Char
getActualCell line pos
  | pos >= 0 && pos < length line = line !! pos
  | otherwise = ' '

goToNextCell :: String -> Int -> Int -> Char
goToNextCell line pos rule
  | calcpos rule (if getActualCell line (pos - 1) == ' ' then 0 else 1)
                      (if getActualCell line pos == ' ' then 0 else 1)
                      (if getActualCell line (pos + 1) == ' ' then 0 else 1)
                       == 1 = '*'
  | otherwise = ' '

getRV :: [String] -> Maybe String
getRV [] = Nothing
getRV ("--rule":value:_) = Just value
getRV (_:rest) = getRV rest

getLV :: [String] -> Maybe String
getLV [] = Nothing
getLV ("--lines":value:_) = Just value
getLV (_:rest) = getLV rest

getWV :: [String] -> Maybe String
getWV [] = Just "80"
getWV ("--window":value:_) = Just value
getWV (_:rest) = getWV rest

getMV :: [String] -> Maybe String
getMV [] = Just "0"
getMV ("--start":value:_) = Just value
getMV (_:rest) = getMV rest

isValidA :: String -> Bool
isValidA arg =
  arg `elem` ["--rule", "--start", "--lines", "--window", "--move"]

isVR :: String -> Bool
isVR ruleVal =
  case reads ruleVal :: [(Int, String)] of
    [(value, _)] -> value `elem` [30, 90, 110]
    _ -> False

isVL :: String -> Bool
isVL lineVal =
  case reads lineVal :: [(Int, String)] of
    [(_, _)] -> True
    _ -> False

isVW :: String -> Bool
isVW windowVal =
  case reads windowVal :: [(Int, String)] of
    [(value, _)] -> value >= 0
    _ -> False

isVM :: String -> Bool
isVM moveVal =
  case reads moveVal :: [(Int, String)] of
    [(_, _)] -> True
    _ -> False

applyRule :: String -> Int -> String
applyRule line rule =
  [goToNextCell line pos rule | pos <- [0..length line - 1]]

gen :: String -> Int -> Int -> Int -> Int -> IO ()
gen startline rule line window move =
  let wLen = window
      wMove = window + move + move
      exSLine = replicate (wLen `div` 2 - wMove `div` 2) ' '
        ++ startline ++ replicate (wLen `div` 2 - wMove `div` 2) ' '
      lDisp = take line $ iterate (\actLine -> applyRule actLine rule) exSLine
  in mapM_ (putStrLn.take window.drop (wMove `div` 2 - window `div` 2)) lDisp

pT :: Int -> IO ()
pT n = putStrLn (replicate n ' ' ++ "*" ++ replicate n ' ')

bI :: Int -> Int -> (Int -> IO ()) -> IO ()
bI x y printFunc =
  printFunc x >> bI (x + 1) (y + 1) printFunc

main :: IO ()
main = do
  a <- getArgs
  case (getRV a, getLV a, getWV a, getMV a) of
    (Just rV, Just lV, Just wV, Just mV) ->
      if and [isValidA "--rule" && isVR rV, isValidA "--lines" && isVL lV,
              isValidA "--window" && isVW wV, isValidA "--start" && isVM mV]
      then let(r,l,w,m)=(read rV::Int,read lV::Int,read wV::Int,- read mV::Int)
        in gen(replicate(w`div`2)' '++"*"++replicate(w`div`2 - 1)' ') r l w m
      else putStrLn "Please put a number in the argument after --something."
    _ -> if getLV a == Nothing then bI 1 2 pT else putStrLn "Invalid arguments"