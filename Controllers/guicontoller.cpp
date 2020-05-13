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
   connect(main->widget2->btnNextPro,&QPushButton::clicked, main->widget2->pStackWidget,onAllocateNewClicked);
   connect(main->widget2->btnPrevPro,&QPushButton::clicked, main->widget2->pStackWidget,onDeallocateClicked);
//   connect(main->widget2->btnPrevPro,&QPushButton::clicked, main->widget2->pStackWidget,onAllocateClicked);

   connect(main->widget2->btnReset,&QPushButton::clicked,main->sWidget,onResetClicked);
   connect(main->widget2->processesList,&QListWidget::itemDoubleClicked,main->widget2->pStackWidget,onProClicked);

   connect(main->widget2->pStack->processName,&QLineEdit::textEdited,main->widget2->pStackWidget,onProNameChanged);
   connect(main->widget2->pStack->processName,&QLineEdit::textEdited,main->widget2->processesList,updateProCount);
}
void GUIContoller::onNxtClicked()
{
//    if(main->sWidget->currentIndex()==0)
    main->sWidget->setCurrentIndex(1);
    main->setWindowTitle("Processses Init");
    main->widget2->pStackWidget->setCurrentIndex(0);
    //    main->widget2->pStack->setTitle(main->widget2->p->value(0));

}
void GUIContoller::addHole()
{
    main->widget1->memTable->insertRow(main->widget1->memTable->rowCount());
}
void GUIContoller::delHole()
{
    main->widget1->memTable->removeRow(main->widget1->memTable->currentRow());
}

/*void GUIContoller::onNxtProClicked()
{
    int n_process = main->widget2->p->size();
    int index = main->widget2->pStackWidget->currentIndex();
    main->widget2->pStackWidget->setCurrentIndex((index+1)%n_process);
//    main->widget2->pStack->setTitle(main->widget2->p->value(main->widget2->pStackWidget->currentIndex()));

}
void GUIContoller::onPrevProClicked()
{
//    main->widget2->pStack->setTitle(main->widget2->);
    int n_process = main->widget2->p->size();
    int index = main->widget2->pStackWidget->currentIndex();
//    qDebug()<<n_process<<" "<<index;
    main->widget2->pStackWidget->setCurrentIndex((index-1)%n_process);
//    main->widget2->pStack->setTitle(main->widget2->p->value(main->widget2->pStackWidget->currentIndex()));

}*/
void GUIContoller::onAllocateNewClicked()
{
    int num = main->widget2->pStackWidget->count()+1;
    main->widget2->pStack = new ProcessStack(main->widget2,"P"+QString::number(num));
    main->widget2->pStackWidget->addWidget(main->widget2->pStack);
    main->widget2->pStackWidget->setCurrentWidget(main->widget2->pStack);

    main->widget2->processesList->addItem(main->widget2->pStack->title());
    connect(main->widget2->pStack->processName,&QLineEdit::textEdited,main->widget2->pStackWidget,onProNameChanged);
    connect(main->widget2->pStack->processName,&QLineEdit::textEdited,main->widget2->processesList,updateProCount);

}
void GUIContoller::onDeallocateClicked()
{
    qDebug()<<"Process Deallocated";
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    QString title = main->widget2->pStack->title();
//    qDebug()<<main->widget2->btnPrevPro->text();
    if (main->widget2->btnPrevPro->text()=="Deallocate Process")
    {
        //remove from memory and
//        main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
        main->widget2->pStack->setTitle(main->widget2->pStack->processName->text()+"(Deallocated)");
//        qDebug()<<"reached";
        main->widget2->processesList->item(main->widget2->pStackWidget->currentIndex())->setText(main->widget2->pStack->title());
        main->widget2->btnPrevPro->setText("Allocate Process");
    }
    else if (main->widget2->btnPrevPro->text()=="Allocate Process"&&title.contains("Deallocated"))
    {
        main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
        main->widget2->btnPrevPro->setText("Deallocate Process");
        main->widget2->pStack->setTitle(title.remove("(Deallocated)"));
        main->widget2->processesList->currentItem()->setText(title.remove("(Dealloacted)"));
    }
}
void GUIContoller::onAllocateClicked()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    QString title = main->widget2->pStack->title();
    if (main->widget2->btnPrevPro->text()=="Allocate process"&&title.contains("Deallocated"))
        {
            main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
            main->widget2->btnPrevPro->setText("Deallocate Process");
            main->widget2->pStack->setTitle(title.remove("(Deallocated)"));
        }
}
void GUIContoller::addSeg()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    main->widget2->pStack->processTable->insertRow(main->widget2->pStack->processTable->rowCount());
  //  processTable->insertRow(main->widget2->pStack->processTable->rowCount());
}
void GUIContoller::delSeg()
{
    main->widget2->pStack->processTable->removeRow(main->widget2->pStack->processTable->currentRow());
}
void GUIContoller::onResetClicked()
{
    main->sWidget->setCurrentIndex(0);
    int n_process = main->widget2->p->size(); //or table.count()
    for(int i = n_process; i > 0; i--)
    {
        QWidget* widget = main->widget2->pStackWidget->widget(i);
        main->widget2->pStackWidget->removeWidget(widget);
        widget->deleteLater();
    }
    //Resetting ProcessWidget
    main->widget2->pStackWidget->setCurrentIndex(0);
    main->widget2->pStack = dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    main->widget2->pStack->processTable->clear();
    main->widget2->pStack->processTable->setRowCount(0);

    //Resetting HolesWidget
    main->widget1->memTable->clear();
    main->widget1->memTable->setRowCount(0);
}
void GUIContoller::onProClicked()
{
    //check if the process's name(pstack->title) contains "deallocated"
    //if found main->widget2->btnPrevPro->setText("Allocate Process")

    main->widget2->pStackWidget->setCurrentIndex(main->widget2->processesList->currentIndex().row());
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    QString title = main->widget2->pStack->title();
    if (title.contains("Deallocated"))
    {
        main->widget2->btnPrevPro->setText("Allocate Process");
    }
    else
    {
        main->widget2->btnPrevPro->setText("Deallocate Process");
    }
    qDebug()<<"reached"<<main->widget2->pStackWidget->currentIndex();
}
void GUIContoller::onProNameChanged()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    main->widget2->pStack->setTitle(main->widget2->pStack->processName->text());
//    main->widget2->processesList->item(main->widget2->pStackWidget->currentIndex());

}
void GUIContoller::updateProCount()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    main->widget2->processesList->item(main->widget2->pStackWidget->currentIndex())->setText(main->widget2->pStack->processName->text());
}
QString GUIContoller:: setBtnAllocate()
{

}

