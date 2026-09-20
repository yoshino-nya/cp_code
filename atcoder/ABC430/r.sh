g++ -Wall -Wextra -Wshadow -fsanitize=address -std=c++20 $1.cpp -o $1
./$1 | tee 1.out