#include "border.h"

Border::Border()
{
    uborder=0;
    dborder=0;
    lborder=0;
    rborder=0;
}
void Border::GetBorder(int block[4][4])
{
    for(int i=3;i>=0;i--)
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==1)
            {uborder=i;break;}
        }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(block[i][j]==1)
            {
                dborder=i;
                break;
            }
        }
    for(int j=3;j>=0;j--)
        for(int i=0;i<4;i++)
        {
            if(block[i][j]==1)
            {
                lborder=j;
                break;
            }
        }
    for(int j=0;j<4;j++)
        for(int i=0;i<4;i++)
        {
            if(block[i][j]==1)
            {
                rborder=j;
                break;
            }
        }
}
