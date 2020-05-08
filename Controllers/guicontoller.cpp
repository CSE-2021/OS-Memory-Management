#include "guicontoller.h"
MainWindow *GUIContoller::main;
HolesWidget *GUIContoller::w1;

void GUIContoller::RegisterObject(MainWindow *m){
    main = m;
   connect(w1->btnNext,&QPushButton::clicked,main->sWidget,onNxtClicked);
}
void GUIContoller::onNxtClicked()
{
    if(main->sWidget->currentIndex()==0)
    main->sWidget->setCurrentIndex(1);
    if(main->sWidget->currentIndex()==1)
    main->sWidget->setCurrentIndex(0);
}
