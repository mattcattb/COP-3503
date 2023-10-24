build:
	g++ -std=c++11 -o project2.out src/main.cpp src/Image.cpp

run: 
	./project2.out output/part1.tga input/layer1.tga multiply input/pattern1.tga
	./project2.out output/part2.tga input/car.tga subtract input/layer2.tga  
	./project2.out output/part3.tga input/layer1.tga multiply input/pattern2.tga screen input/text.tga
	./project2.out output/part4.tga input/layer2.tga multiply input/circles.tga subtract input/pattern2.tga
	./project2.out output/part5.tga input/layer1.tga overlay input/pattern1.tga
	./project2.out output/part6.tga input/car.tga addgreen 200
	./project2.out output/part7.tga input/car.tga scalered 4 scaleblue 0
	./project2.out output/part8_r.tga input/car.tga onlyred
	./project2.out output/part8_g.tga input/car.tga onlygreen
	./project2.out output/part8_b.tga input/car.tga onlyblue
	./project2.out output/part9.tga input/layer_red.tga combine input/layer_green.tga input/layer_blue.tga
	./project2.out output/part10.tga input/text2.tga flip 
	
tasks:
	./project2.out output/part11.tga input/circles.tga multiply input/layer1.tga
	./project2.out output/part12.tga input/layer1.tga flip
	./project2.out output/part13.tga input/layer1.tga subtract input/layer2.tga
	

hidden: 
	./project2.out output/part14.tga input/car.tga flip flip flip flip
	./project2.out output/part15.tga input/car.tga subtract input/layer1.tga multiply circles.tga flip
	./project2.out output/part16.tga input/car.tga scaleblue 3 scalered 2 scalegreen 0

clean:
	del output\part1.tga
	del output\part2.tga
	del output\part3.tga
	del output\part4.tga
	del output\part5.tga
	del output\part6.tga
	del output\part7.tga
	del output\part8_b.tga
	del output\part8_g.tga
	del output\part8_r.tga
	del output\part9.tga
	del output\part10.tga

