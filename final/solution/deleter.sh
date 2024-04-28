for i in {1..10}
do
	mv /users/jaspenc/project2/bedfiles/negative$i.bed /users/jaspenc/project2
	mv /users/jaspenc/project2/finals/finalStorage/final$i.txt /users/jaspenc/project2
	mv /users/jaspenc/project2/finals/finalStorage/negFinal$i.txt /users/jaspenc/project2
	rm negative$i.bed
	rm negative$i.txt
	rm final$i.txt
	rm negFinal$i.txt
	rm avg$i.txt
	rm length$i.txt
done
