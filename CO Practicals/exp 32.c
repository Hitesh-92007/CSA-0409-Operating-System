#include <stdio.h>

int main()
{
    int pages[50], frames[10], time[10];
    int n, f, i, j, pos, min, pageFault = 0;
    int flag, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        flag = 0;
        counter++;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                time[j] = counter;
                break;
            }
        }

        if(flag == 0)
        {
            pos = -1;
            min = 9999;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = counter;
            pageFault++;
        }

        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", pageFault);

    return 0;
}
