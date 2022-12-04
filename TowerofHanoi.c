#include <stdio.h>
void towerOfHanoi(int n, char source, char destination,
                  char intermediate);

int main()
{
    int N;
    printf("Enter number of Disks: ");
    scanf("%d", &N);
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}

void towerOfHanoi(int n, char source, char destination,
                  char intermediate)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, source, intermediate, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination );
    towerOfHanoi(n - 1, intermediate, destination, source);
}
 
// Move disk 1 from rod A to rod C
// Move disk 2 from rod A to rod B
// Move disk 1 from rod C to rod B
// Move disk 3 from rod A to rod C
// Move disk 1 from rod B to rod A
// Move disk 2 from rod B to rod C
// Move disk 1 from rod A to rod C