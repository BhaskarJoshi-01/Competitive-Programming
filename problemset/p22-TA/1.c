#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    if (n < 2)
    {
        printf("0\n");
        return 0;
    }
    int arr[n];
    int ans = 0;
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total_sum += arr[i];
    }
    if (total_sum % 3 == 0)
    {
        int i = 0;
        int packet = total_sum / 3;
        int length = sizeof(arr) / sizeof(arr[0]);
        int sum = 0;
        while (i != length)
        {
            sum += arr[i];
            if (sum == packet || !sum)
            {
                sum = 0;
                ans++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }
    printf("%d\n", ans - 2 > 0 ? ans - 2 : 0);
    return 0;
}
