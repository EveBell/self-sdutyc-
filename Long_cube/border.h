#ifndef BORDER_H
#define BORDER_H


class Border
{
public:
    Border();
    void GetBorder(int block[4][4]);

    int uborder;
    int dborder;
    int lborder;
    int rborder;
};

#endif // BORDER_H
