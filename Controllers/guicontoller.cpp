#include "guicontoller.h"
MainWindow *GUIContoller::main;
MemoryController *GUIContoller::m;

void GUIContoller::RegisterObject(MainWindow *m){
    main = m;
   connect(main->widget1->btnNext,&QPushButton::clicked,main->sWidget,onNxtClicked);
//   connect(main->)
   connect(main->widget1->btnAddHole,&QPushButton::clicked,main->widget1->memTable,addHole);
   connect(main->widget1->btnDelHole,&QPushButton::clicked,main->widget1->memTable,delHole);
   connect(main->widget1->memSizeEdit,&QLineEdit::returnPressed,main->sc,onMemSizeChanged);

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
    if(main->widget1->allocatorBox->currentIndex()==0)
    {
        QMessageBox e;
        e.setText("Please Choose an allocation method");
        e.exec();
        return;
    }
    else if(main->widget1->allocatorBox->currentIndex()==1) m->setAllocationType(BEST_FIT);
    else m->setAllocationType(FIRST_FIT);

    for(int i=0; i < main->widget1->memTable->rowCount(); i++)
       {
           for(int j=0; j < main->widget1->memTable->columnCount(); j++)
           {
               bool flag =main->widget1->memTable->item(i,j) == nullptr;

               if (!flag) /* the cell is not empty */
               {
                   main->sWidget->setCurrentIndex(1);
                   main->setWindowTitle("Processses Init");
                   main->widget2->pStackWidget->setCurrentIndex(0);
               }
               else /* the cell is empty */
               {
                   main->sWidget->setCurrentIndex(0);
               }
           }
       }

    int n_holes = main->widget1->memTable->rowCount();
    for(int i = 0 ; i < n_holes  ; i++)
    {
        int base = main->widget1->memTable->item(i,1)->text().toInt();
        int limit = main->widget1->memTable->item(i,2)->text().toInt();
        m->deallocateSegment(base,limit);
    }
    for(Segment *s : *(m->getSegments()))
    {
        qDebug() << s->getName() << s->getBase() << s->getLimit();
        if(s->getName()=="HOLE")
        {
            main->segment = new Shape(0,s->getBase(),300,s->getLimit(),Shape::RECTANGLE2,1,QBrush(Qt::gray,Qt::SolidPattern));
            main->segment->setText("Hole",Shape::MIDDLE);
            main->sc->drawShape(main->segment);
        }
    }
}
void GUIContoller::addHole()
{
    main->widget1->memTable->insertRow(main->widget1->memTable->rowCount());
    int i = main->widget1->memTable->rowCount()-1;
    main->widget1->memTable->setItem(i,0,new QTableWidgetItem("Hole "+QString::number(i+1)));
}
void GUIContoller::delHole()
{
    main->widget1->memTable->removeRow(main->widget1->memTable->currentRow());
}

void GUIContoller::onAllocateNewClicked()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    QString p_name = main->widget2->pStack->title();
    int rcount = main->widget2->pStack->processTable->rowCount();
    for(int i=0; i < rcount; i++)
    {
       for(int j=0; j < main->widget2->pStack->processTable->columnCount(); j++)
         {
               if(j == 1) continue;
               bool flag = main->widget2->pStack->processTable->item(i,j) == nullptr;

               if (flag) /* the cell is not empty */
                return;
          }
       }
    QVector<QString> segmentNames;
    QVector<unsigned long> segmentSizes;
    for(int a = 0; a < rcount; a++)
    {
        QString name = main->widget2->pStack->processTable->item(a,0)->text();
//        int base = main->widget2->pStack->processTable->item(a,1)->text().toInt();
        int size = main->widget2->pStack->processTable->item(a,2)->text().toInt();
        segmentNames.append(name);
        segmentSizes.append(size);
    }
    bool allocated =  m->allocateProcess(p_name, segmentNames, segmentSizes);
    if(!allocated)
    {
        main->widget2->pStack->setTitle(main->widget2->pStack->title()+"(Deallocated)");
        main->widget2->processesList->item(main->widget2->pStackWidget->currentIndex())->setText(main->widget2->pStack->title());
    }else
    {
        int rows = main->widget2->pStack->processTable->rowCount();
        for(int a = 0; a < rows; a++){
            QString s_name =  main->widget2->pStack->processTable->item(a,0)->text();
            for(Segment *s : *(m->getSegments())){
                QString base = QString::number(s->getBase());
                if(!s->getName().compare(s_name)) main->widget2->pStack->processTable->item(a,1)->setText(base);
            }
        }
    }

    bool err = false;
    if(!err)
    {
        int num = main->widget2->pStackWidget->count()+1;
        main->widget2->pStack = new ProcessStack(main->widget2,"P"+QString::number(num));
        main->widget2->pStackWidget->addWidget(main->widget2->pStack);
        main->widget2->pStackWidget->setCurrentWidget(main->widget2->pStack);

        main->widget2->processesList->addItem(main->widget2->pStack->title());
        connect(main->widget2->pStack->processName,&QLineEdit::textEdited,main->widget2->pStackWidget,onProNameChanged);
        connect(main->widget2->pStack->processName,&QLineEdit::textEdited,main->widget2->processesList,updateProCount);
    }
    for(Segment *s : *(m->getSegments()))
    {
        qDebug() << s->getName() << s->getBase() << s->getLimit();
        if(s->getName()!="HOLE"&&s->getName()!="system")
        {
            qDebug()<<"Process Name: Crashing is here ";//<<m->getProcessName(s);
            if(p_name==m->getProcessName(s))
            {
                main->segment = new Shape(0,s->getBase(),300,s->getLimit(),Shape::RECTANGLE2,1,QBrush(Qt::darkYellow,Qt::SolidPattern));
                main->segment->setText((p_name+"\n")+s->getName(),Shape::MIDDLE);
                main->sc->drawShape(main->segment);
            }
        }
    }

}
void GUIContoller::onDeallocateClicked()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    QString title = main->widget2->pStack->title();
    if (main->widget2->btnPrevPro->text()=="Deallocate Process")
    {
//        m->deallocateProcess(title);
        //remove from memory and
//        main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
        main->widget2->pStack->setTitle(main->widget2->pStack->title()+"(Deallocated)");
        main->widget2->processesList->item(main->widget2->pStackWidget->currentIndex())->setText(main->widget2->pStack->title());
        main->widget2->btnPrevPro->setText("Allocate Process");
    }

    else if (main->widget2->btnPrevPro->text()=="Allocate Process"&&title.contains("Deallocated"))
    {
        m->reallocateProcess(title);
        main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
        main->widget2->btnPrevPro->setText("Deallocate Process");
        main->widget2->pStack->setTitle(title.remove("(Deallocated)"));
        main->widget2->processesList->currentItem()->setText(title.remove("(Dealloacted)"));
    }
    reDraw();
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
            reDraw();
        }
}
void GUIContoller::addSeg()
{
    main->widget2->pStack =dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    main->widget2->pStack->processTable->insertRow(main->widget2->pStack->processTable->rowCount());
    int rcount = main->widget2->pStack->processTable->rowCount()-1;
    main->widget2->pStack->processTable->setItem(rcount,1,new QTableWidgetItem());
    QTableWidgetItem *i = main->widget2->pStack->processTable->item(rcount,1);
    qDebug() << i << rcount;
    i->setFlags(i->flags() & ~Qt::ItemIsEnabled);
  //  processTable->insertRow(main->widget2->pStack->processTable->rowCount());
}
void GUIContoller::delSeg()
{
    main->widget2->pStack->processTable->removeRow(main->widget2->pStack->processTable->currentRow());
}
void GUIContoller::onResetClicked()
{
    delete m;
    //Resetting memory size
    main->sc->reset();
    main->widget1->memSizeEdit->clear();
    main->widget1->allocatorBox->setCurrentIndex(0);

    //Removing Processes Widgets
    main->sWidget->setCurrentIndex(0);
    int n_process = main->widget2->pStackWidget->count(); //or table.count()
    for(int i = 1; i <n_process; i++)
    {
        main->widget2->pStackWidget->setCurrentIndex(i);
        main->widget2->pStack = dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
        main->widget2->pStackWidget->removeWidget( main->widget2->pStack);
        main->widget2->pStack->deleteLater();
    }
    //Resetting ProcessWidget
    main->widget2->pStackWidget->setCurrentIndex(0);
    main->widget2->pStack = dynamic_cast<ProcessStack*>(main->widget2->pStackWidget->currentWidget());
    main->widget2->pStack->setTitle("P1");
    main->widget2->pStack->processTable->clearContents();
    main->widget2->pStack->processTable->setRowCount(0);

    //Rsetting ProcessNameEdit
    main->widget2->pStack->processName->clear();

    main->widget2->processesList->clear();
    main->widget2->processesList->addItem("P1");

    //Resetting HolesWidget
    main->widget1->memTable->clearContents();
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
//QString GUIContoller:: setBtnAllocate()
//{

//}
void GUIContoller::onMemSizeChanged()
{
    main->sc->reset();
    int len = main->widget1->memSizeEdit->text().toInt();
    m = new MemoryController(len);
    main->Memory= new Shape(0,0,300,len,Shape::RECTANGLE2,4,QBrush(Qt::red,Qt::CrossPattern)); // changes here
    main->Memory->setText("Memory",Shape::MIDDLE);
    main->sc->drawShape(main->Memory);

}
void GUIContoller::reDraw()
{for(Segment *s : *(m->getSegments()))
    {
        qDebug() <<"after dealloc "<< s->getName() << s->getBase() << s->getLimit();
        if(s->getName()=="HOLE")
        {
                main->segment = new Shape(0,s->getBase(),300,s->getLimit(),Shape::RECTANGLE2,1,QBrush(Qt::gray,Qt::SolidPattern));
                main->segment->setText(s->getName(),Shape::MIDDLE);
                main->sc->drawShape(main->segment);
        }
        else if(s->getName()=="system")
        {
            main->segment = new Shape(0,s->getBase(),300,s->getLimit(),Shape::RECTANGLE2,1,QBrush(Qt::red,Qt::CrossPattern));
            main->segment->setText(s->getName(),Shape::MIDDLE);
            main->sc->drawShape(main->segment);
        }
        else
        {
            main->segment = new Shape(0,s->getBase(),300,s->getLimit(),Shape::RECTANGLE2,1,QBrush(Qt::green,Qt::SolidPattern));
            main->segment->setText((m->getProcessName(s)+"\n")+s->getName(),Shape::MIDDLE);
            main->sc->drawShape(main->segment);
        }
    }
}
