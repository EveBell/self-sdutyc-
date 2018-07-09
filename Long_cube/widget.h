#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <border.h>
#include <QTimer>
namespace Ui {
class Widget;
}
const int BLOCK_SIZE=25;
const int AREA_COL=14;
const int AREA_ROW=24;//24行14列

class block_pos
{
public:
    block_pos();
    block_pos(int xx,int yy);

    int pos_x;
    int pos_y;
};
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void InitGame();
    void StartGame();
    void GameOver();
    void ResetBlock();
    void CreatBlock(int block[4][4],int ID);
    bool isCollide(int x,int y,Direction Dir);
    void BlockRotate(int block[4][4]);
    void BlockMove(Direction Dir);
    void ConvertStable(int x,int y);

public:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::Widget *ui;
    QPainter *painter;
    QPushButton *button_start;
    QPushButton *button_stop;
    QBrush *brush;
private:
    int game_area[AREA_ROW][AREA_COL];
    block_pos pos_point;
    int cur_Block[4][4];
    int next_Block[4][4];
    Border cur_Border;
    bool isStable;
    int score=0;
    int game_timer;//下落的计时器
    int paint_timer;//画方块的
    int speed_ms;//下落速度
    int refresh_ms;//刷新速度
};

#endif // WIDGET_H
