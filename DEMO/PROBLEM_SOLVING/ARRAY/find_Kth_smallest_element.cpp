/**
	Use quicksort but tweak it little bit.
	{70,40,10,50,20,80,30,100} now k= 3 then output will 30


Quicksort:
	70,40,10,50,20,80,30 ==> 100 is pivot so put 100 in appropriate position
	70,40,10,50,20,80,30,100 ==> {70,40,10,50,20,80,30} & {}
	70,40,10,50,20,80 ==> 30 is pivot so put 30(index=6) in its appropriate position
	20,40,10,50,70,80 =>left=0,right=4 
	20,10,40,50,70,80 =>left=1,right=2
	20,10,30,50,70,80,40 ==>pivot =(2 == k-1) so return a[pivot] 

  */
