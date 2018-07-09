#include "widget.h"
#include "ui_widget.h"
#include <border.h>
#include <QPainter>
#include <QPushButton>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPen>
#include <QBrush>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(640,700);
    button_start=new QPushButton("START",this);
    button_start->move(468,330);
    connect(button_start,&QPushButton::pressed,this,InitGame);
    button_stop=new QPushButton("STOP",this);
    button_stop->move(468,380);

    for(int i=0;i<AREA_ROW;i++)
        for(int j=0;j<AREA_COL;j++)
            game_area[i][j]=0;
}
int item1[4][4]=
{
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0}
};
int item2[4][4]=
{
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,0,0}
};
int item3[4][4]=
{
    {0,1,1,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,0,0,0}
};
int item4[4][4]=
{
    {0,0,0,0},
    {0,1,1,1},
    {0,0,1,0},
    {0,0,0,0}
};
int item5[4][4]=
{
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}
};
int item6[4][4]=
{
    {0,0,1,0},
    {0,1,1,0},
    {0,1,0,0},
    {0,0,0,0}
};
int item7[4][4]=
{
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
block_pos::block_pos()
{
    pos_x=0;
    pos_y=0;
}
block_pos::block_pos(int xx, int yy)
{
    pos_x=xx;
    pos_y=yy;
}
Widget::~Widget()
{
    delete ui;
}
inline void Block_Copy(int block[4][4],int mblock[4][4])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            block[i][j]=mblock[i][j];
}

void Widget::paintEvent(QPaintEvent *event)
{
    painter=new QPainter;
    painter->begin(this);

    //painter->setBrush(QBrush(Qt::red,Qt::SolidPattern));

    painter->drawRect(0,0,640,700);//外边框

    painter->setPen(QPen(Qt::black,3,Qt::SolidLine));
    painter->drawRect(40,40,BLOCK_SIZE*AREA_COL,BLOCK_SIZE*AREA_ROW);//游戏区域
    painter->drawRect(440,60,BLOCK_SIZE*6,BLOCK_SIZE*8);//预告区域
    painter->drawText(440,300,"显示关卡：");
    painter->drawText(440,500,"分数：");
    painter->drawText(440,540,"剩余时间：");

    for(int i=0;i<AREA_ROW;i++)
        for(int j=0;j<AREA_COL;j++)
        {
            if(game_area[i][j]==1)
            {
               // brush->setColor(Qt::red);
              //  painter->setBrush(*brush);
                painter->drawRect(j*BLOCK_SIZE+40,i*BLOCK_SIZE+40,BLOCK_SIZE,BLOCK_SIZE);
            }
            else if(game_area[i][j]==2)
            {
                painter->drawRect(j*BLOCK_SIZE+40,i*BLOCK_SIZE+40,BLOCK_SIZE,BLOCK_SIZE);
            }
        }

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(next_Block[i][j]==1)
                painter->drawRect(440+20+BLOCK_SIZE*j,60+20+BLOCK_SIZE*i,BLOCK_SIZE,BLOCK_SIZE);
    //painter->end();
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        BlockMove(UP);
        break;
    case Qt::Key_Down:
        BlockMove(DOWN);
        break;
    case Qt::Key_Left:
        BlockMove(LEFT);
        break;
    case Qt::Key_Right:
        BlockMove(RIGHT);
        break;
    case Qt::Key_Space:
        BlockMove(SPACE);
        break;
    default:
        break;
    }
}
void Widget::CreatBlock(int block[4][4],int ID)
{
    switch(ID)
    {
    case 0:Block_Copy(block,item1);
        break;
    case 1:Block_Copy(block,item2);
        break;
    case 2:Block_Copy(block,item3);
        break;
    case 3:Block_Copy(block,item4);
        break;
    case 4:Block_Copy(block,item5);
        break;
    case 5:Block_Copy(block,item6);
        break;
    case 6:Block_Copy(block,item7);
        break;
    default:
        break;
    }
}
void Widget::BlockRotate(int block[4][4])
{
    int temp[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            temp[3-j][i]=block[i][j];//顺时针旋转
        }
   // Block_Copy(block,temp);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            block[i][j]=temp[i][j];
        }
}
bool Widget::isCollide(int x,int y,Direction Dir)
{
    bool flag=0;
    int temp[4][4];
    Block_Copy(temp,cur_Block);//用拷贝下的临时方块做判断，先假定它已经完成那个方向的移动
    Border temp_border;
    temp_border.GetBorder(temp);
    switch(Dir)
    {
    case UP:
        BlockRotate(temp);
        temp_border.GetBorder(temp);//旋转取得新的边界
        break;
    case DOWN:
        y+=1;
        break;
    case LEFT:
        x-=1;
        break;
    case RIGHT:
        x+=1;
        break;

    default:
        break;
    }
//看它执行相应操作后会不会碰到边界
    for(int i=temp_border.uborder;i<=temp_border.dborder;i++)
        for(int j=temp_border.lborder;j<=temp_border.rborder;j++)
        {
            if(game_area[i+y][j+x]==2&&temp[i][j]==1||x+temp_border.lborder<0||x+temp_border.rborder>AREA_COL-1)
                flag=1;
        }

    return flag;
}
void Widget::ConvertStable(int x, int y)
{
    for(int i=cur_Border.uborder;i<=cur_Border.dborder;i++)
        for(int j=cur_Border.lborder;j<=cur_Border.rborder;j++)
        {
            if(cur_Block[i][j]==1)
                game_area[y+i][x+j]=2;
        }
}
void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==game_timer)
        BlockMove(DOWN);
    if(event->timerId()==paint_timer)
        update();
}
void Widget::StartGame()
{
    game_timer=startTimer(speed_ms);
    paint_timer=startTimer(refresh_ms);
    int block_id=rand()%7;
    CreatBlock(next_Block,block_id);
    ResetBlock();
}
void Widget::InitGame()
{
    for(int i=0;i<AREA_ROW;i++)
        for(int j=0;j<AREA_COL;j++)
            game_area[i][j]=0;
    speed_ms=800;
    refresh_ms=30;
    srand(time(0));
    score=0;
    StartGame();
}
void Widget::ResetBlock()//把当前的下一个方块给当前方块，并生成下一个下一个方块
{
    Block_Copy(cur_Block,next_Block);
    cur_Border.GetBorder(next_Block);

    int block_id=rand()%7;
    CreatBlock(next_Block,block_id);

    block_pos start_point;
    start_point.pos_x=AREA_COL/2-2;
    start_point.pos_y=0;
    pos_point=start_point;
}
void Widget::GameOver()
{
    killTimer(game_timer);
    killTimer(paint_timer);

    QMessageBox::information(this,"FAIL","GAME OVER");
}
void Widget::BlockMove(Direction Dir)
{
    switch(Dir)
    {
    case UP:
    {
        if(isCollide(pos_point.pos_x,pos_point.pos_y,UP))
            break;

        int last_Block[4][4];
        Block_Copy(last_Block,cur_Block);
        BlockRotate(cur_Block);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                if(last_Block[i][j]==1)
                    game_area[pos_point.pos_y+i][pos_point.pos_x+j]=0;
                if(cur_Block[i][j]==1)
                    game_area[pos_point.pos_y+i][pos_point.pos_x+j]=1;
            }
        cur_Border.GetBorder(cur_Block);//若旋转成功，重新取一次边界,并把原来旋转前的区域置0，旋转后的区域置1
    }
        break;
    case DOWN:
        if(pos_point.pos_y+cur_Border.dborder==AREA_ROW-1)//如果下落一格刚好到达底部那么久变成稳定方块
        {
            ConvertStable(pos_point.pos_x,pos_point.pos_y);
            ResetBlock();
            break;
        }
        if(isCollide(pos_point.pos_x,pos_point.pos_y,DOWN))//如果撞到了什么那么就变成稳定方块
        {
            ConvertStable(pos_point.pos_x,pos_point.pos_y);
            ResetBlock();
            break;
        }

            for(int j=cur_Border.lborder;j<=cur_Border.rborder;j++)//将掉落后最开始那一行的方块清掉
                if(cur_Block[0][j]==1)
                    game_area[pos_point.pos_y][pos_point.pos_x+j]=0;
            pos_point.pos_y+=1;

            for(int i=0;i<4;i++)
                for(int j=cur_Border.lborder;j<=cur_Border.rborder;j++)
                    if(pos_point.pos_y+i<=AREA_ROW-1&&game_area[pos_point.pos_y+i][pos_point.pos_x+j]!=2)
                        game_area[pos_point.pos_y+i][pos_point.pos_x+j]=cur_Block[i][j];
            break;


   case LEFT:
        if(pos_point.pos_x+cur_Border.lborder==0||isCollide(pos_point.pos_x,pos_point.pos_y,LEFT))
            break;

        for(int i=cur_Border.uborder;i<=cur_Border.dborder;i++)
            if(cur_Block[i][cur_Border.rborder]==1)
                game_area[pos_point.pos_y+i][pos_point.pos_x+cur_Border.rborder]=0;
        pos_point.pos_x-=1;

        for(int i=cur_Border.uborder;i<=cur_Border.dborder;i++)
            for(int j=0;j<4;j++)
                if(pos_point.pos_x+j>=0&&game_area[pos_point.pos_y+i][pos_point.pos_x+j]!=2) //注意场景数组不越界
                    game_area[pos_point.pos_y+i][pos_point.pos_x+j]=cur_Block[i][j];
        break;
   case RIGHT:
        if(pos_point.pos_x+cur_Border.rborder==AREA_COL-1||isCollide(pos_point.pos_x,pos_point.pos_y,RIGHT))
            break;

        for(int i=cur_Border.uborder;i<=cur_Border.dborder;i++)
            if(cur_Block[i][cur_Border.lborder]==1)
                game_area[pos_point.pos_y+i][pos_point.pos_x+cur_Border.lborder]=0;
        pos_point.pos_x+=1;

        for(int i=cur_Border.uborder;i<=cur_Border.dborder;i++)
            for(int j=0;j<4;j++)
                if(pos_point.pos_x+j>=0&&game_area[pos_point.pos_y+i][pos_point.pos_x+j]!=2)
                    game_area[pos_point.pos_y+i][pos_point.pos_x+j]=cur_Block[i][j];
        break;
   case SPACE:
        while(pos_point.pos_y+cur_Border.dborder<AREA_ROW-1&&isCollide(pos_point.pos_x,pos_point.pos_y,DOWN))
        {
            for(int i=cur_Border.lborder;i<=cur_Border.rborder;i++)
            {
                game_area[pos_point.pos_y][pos_point.pos_x+i]=0;
            }
            pos_point.pos_y+=1;
            for(int i=0;i<4;i++)
                for(int j=cur_Border.lborder;j<cur_Border.rborder;j++)
                {
                    if(pos_point.pos_y+1<AREA_ROW-1&&game_area[pos_point.pos_y+i][pos_point.pos_x+j]!=2)
                        game_area[pos_point.pos_y+i][pos_point.pos_x+j]=cur_Block[i][j];
                }
        }
        ConvertStable(pos_point.pos_x,pos_point.pos_y);
        ResetBlock();
        break;
    default:
        break;
    }
    //处理消行，整个场景上面的行依次下移
        int i=AREA_ROW-1;
        int line_count=0; //记消行数
        while(i>=1)
        {
            bool is_line_full=true;
            for(int j=0;j<AREA_COL;j++)
                if(game_area[i][j]!=2)
                {
                    is_line_full=false;
                    i--;
                    break;
                }
            if(is_line_full)
            {
                for(int k=i;k>=1;k--)
                    for(int j=0;j<AREA_COL;j++)
                        game_area[k][j]=game_area[k-1][j];
                line_count++;//每次增加消行的行数
            }
        }
        score+=line_count*10; //得分
       if(score%50==0&&score!=0)
       {
           speed_ms=800/(score/50+1);
           game_timer=startTimer(speed_ms);
       }
        //判断游戏是否结束
        for(int j=0;j<AREA_COL;j++)
            if(game_area[0][j]==2) //最顶端也有稳定方块
                GameOver();

}
