read N
for i in $(seq 1 $N);
do
	cp test/$i.in ./1.in
	./a.out >> a.txt
	mv 1.out Aoutput/$i.out
	./b.out >> b.txt
	mv 1.out Boutput/$i.out
	./c.out >> c.txt
	mv 1.out Coutput/$i.out
	echo $i
done

