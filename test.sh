echo "========================= TEST SIZE 1 ==========================="
gcc -Wall -Werror -Wextra -D BUFFERSIZE=1 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 2 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=2 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 3 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=3 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 4 ==========================="
gcc -Wall -Werror -Wextra -D BUFFERSIZE=4 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 10 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=10 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 21 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=21 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 30 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=30 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 42 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=42 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 100 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=100 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE 1000 ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=1000 get_next_line.c && ./a.out
echo "===================================================================="
echo "========================= TEST SIZE MILLION ==========================="
gcc -Wall -Werror -Wextra  -D BUFFERSIZE=1000000 get_next_line.c && ./a.out
echo "===================================================================="
