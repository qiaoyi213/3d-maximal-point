read N
for i in $(seq 1 $N);
do
	cp test/$i.in ./1.in
	./a.out >> result.txt
	mv 1.out output/$i.out
	echo $i
done

