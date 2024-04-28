for i in {1..10}
do
	echo negative $i
	./negative -a $i
	echo bedtools on the negative
	bedtools getfasta -fi /users/jaspenc/reference/hg38.fa -bed /users/jaspenc/project2/negative$i.bed -fo /users/jaspenc/project2/negative$i.txt
	echo moving negative
	mv negative$i.bed bedfiles
	echo lengthFinder $i
	./lengthFinder -a $i
	echo avgFinder $i
	./avgFinder -a $i
	echo sorting $i positive
	./sort -a $i +
	echo sorting $i negative
	./sort -a $i -
	echo moving finals
	mv final$i.txt finals
	mv negFinal$i.txt finals
done
