#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k, pos, farthest, next;
    int flag, pageFault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        flag = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            pos = -1;
            farthest = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                next = i + 1;

                while(next < n && pages[next] != frames[j])
                    next++;

                if(next > farthest)
                {
                    farthest = next;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            pageFault++;
        }

        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", pageFault);

    return 0;
}
