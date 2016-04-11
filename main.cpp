#include <QApplication>
#include <QImage>
#include <QPainter>
#include <QString>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc!=3){
        fprintf(stderr,"not enough minerals!\n");
        return 1;
    }
    int width=strtol(argv[1],NULL,10);
    int height=strtol(argv[2],NULL,10);

    QImage img(width,height,QImage::Format_RGB888);
    if(img.isNull()){
        fprintf(stderr,"could not allocate memory\n");
        return 2;
    }
    QPainter painter(&img);
    painter.setPen(QColor(255,255,0));
    QFont font=painter.font();
    font.setPixelSize(24);
    painter.setFont(font);

    {
        std::string line;
        int offset=0;
        while(std::getline(std::cin,line)){
            painter.drawText(QRect(0,offset,width,height),0,QString::fromStdString(line));
            offset+=24;
            if(offset>height)break;
        }
    }
    painter.end();
    img.save("filename.png");
    fprintf(stdout,"all is good\n");
    //return a.exec();
    return 0;
}

