#include <QCoreApplication>
#include <QPainter>
#include <QPrinter>
#include <QPdfWriter>
#include <QPagedPaintDevice>
#include <QPen>
#include <QFont>
#include <QColor>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Qt 5
    QPainter *painter = new QPainter();

    QPrinter *printer = new QPrinter(QPrinter::ScreenResolution);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOrientation(QPrinter::Landscape);
    printer->setPaperSize(QPrinter::A3);
    printer->setOutputFileName("test.pdf");
    printer->setCreator("Application");
    printer->setDocName("Report");
    printer->setPrintProgram("The Application");

    if(painter->begin(printer)) // QPaintDevice : printer
    {
        painter->resetTransform();
        QRect rect(10,10, painter->viewport().width()-20, 100);
        painter->fillRect(rect, QColor(150, 200, 150));
        painter->setPen(Qt::blue);
        painter->setFont(QFont("arial",20));
        painter->drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, QString("Qt 5.12"));
        painter->drawRect(rect);
        painter->drawLine(200,200, 400,400);
        painter->drawEllipse(400,400, 200, 50);


        painter->end();
    }
    else
    {
        qDebug() << "error";
    }



    // Qt 6

    return a.exec();
}
