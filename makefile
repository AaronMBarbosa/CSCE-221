all: Stress_ball_test.o Stress_ball.o Jeans_test.o Jeans.o collection-test.cpp
	c++ -std=c++11  Stress_ball_test.o Stress_ball.o Jeans_test.o Jeans.o collection-test.cpp -o test

Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c Jeans.cpp

Jeans_test.o: Jeans_test.cpp Jeans_test.h
	c++ -std=c++11 -c  Jeans_test.cpp

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c  Stress_ball.cpp

Stress_ball_test.o: Stress_ball_test.cpp Stress_ball_test.h
	c++ -std=c++11 -c Stress_ball_test.cpp

clean:
	rm -f *.o test
	
run: test
	./test