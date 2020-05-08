#include "guicontoller.h"
MainWindow *GUIContoller::main;
HolesWidget *GUIContoller::w1;

void GUIContoller::RegisterObject(MainWindow *m){
    main = m;
   connect(main->widget1->btnNext,&QPushButton::clicked,main->sWidget,onNxtClicked);
   connect(main->widget1->btnAddHole,&QPushButton::clicked,main->widget1->memTable,addHole);
   connect(main->widget1->btnDelHole,&QPushButton::clicked,main->widget1->memTable,delHole);

   connect(main->widget2->btnAddSeg,&QPushButton::clicked, main->widget2->pStack->processTable,addSeg);
   connect(main->widget2->btnDelSeg,&QPushButton::clicked, main->widget2->pStack->processTable,delSeg);
}
void GUIContoller::onNxtClicked()
{
    if(main->sWidget->currentIndex()==0)
    main->sWidget->setCurrentIndex(1);
}
void GUIContoller::addHole()
{
    main->widget1->memTable->insertRow(main->widget1->memTable->rowCount());
}
void GUIContoller::delHole()
{
    main->widget1->memTable->removeRow(main->widget1->memTable->currentRow());
}
void GUIContoller::onNxtProClicked()
{
    if(main->sWidget->currentIndex()==0)
    main->sWidget->setCurrentIndex(1);
}
void GUIContoller::addSeg()
{
    main->widget2->pStack->processTable->insertRow(main->widget2->pStack->processTable->rowCount());
}
void GUIContoller::delSeg()
{
    main->widget2->pStack->processTable->removeRow(main->widget2->pStack->processTable->currentRow());
}
