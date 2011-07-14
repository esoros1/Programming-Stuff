
addThree x y z = x + y + z

factorial :: Integer -> Integer
factorial n = product [1..n]

circumference :: Float -> Float
circumference r = 2 * pi * r

circumference' :: Double -> Double
circumference' r = 2 * pi * r

lucky :: Int -> String
lucky 7 = "Lucky 7!!!!!"
lucky x = "Fuck YOU!!!!!"

first :: (a,b,c) -> a
first (x,_,_) = x

head' :: [a] -> a
head' [] = error "Empty List. Fuck You"
head' (x:xs) = x

tell :: (Show a) => [a] -> String
tell [] = "This is an empty List"
tell (x:[]) = "This List has one item: "++ show x
tell (x:y:[]) = "This List has two items: " ++ show x ++ " "++show y
tell (x:y:xs) = "This list has more than two items"

max' :: (Ord a) => a -> a -> a
max' a b
	| a <= b = b
	| otherwise = a

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b 
	| a == b = EQ
	| a > b = GT
	| otherwise = LT


maximum' :: (Ord a) => [a] -> a
maximum' [] = error "Empty list"
maximum' [x] = x
maximum' (x:xs) = max x (maximum' xs)

replicate' :: Int -> a -> [a]
replicate' n x
	| n <= 0 = []
	| otherwise = x: replicate' (n-1) x


reverse' :: [a] -> [a]
reverse' [x] = [x]
reverse' (x:xs) = reverse' xs ++ [x]

elem' :: (Eq a) => a -> [a] -> Bool 
elem' a [] = False
elem' a (x:xs)
	| a == x = True
	| otherwise = elem' a xs

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
	let smallerOrEqual = [a | a <- xs, a <= x]; 
		larger = [a | a <- xs, a > x]
	in quicksort smallerOrEqual ++ [x] ++ quicksort larger


applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)


zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys

chain:: Integer -> [Integer]
chain 1 = [1]
chain n
	| even n = n:chain (n `div` 2)
	| odd n =  n:chain(n*3 + 1)


	 
