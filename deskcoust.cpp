#include "deskcoust.h"
#include "ui_deskcoust.h"
#include "customer.h"
#include "mainwindow.h"
#include "classfood.h"
#include "cardfood.h"
#include "sides.h"
#include "sidescard.h"
#include "ordercard.h"
#include "orderco.h"
#include "code.h"
#include "codecard.h"
#include "code.h"
#include "infocard.h"
#include "algorithm"
#include <QButtonGroup>
#include <QHash>
#include <QDebug>
// deskcoust* deskcoust::ip=nullptr;
struct FoodSummary {
    int count=0;
    double totalPrice= 0;
    QString im;
};
int ba=0;
deskcoust::deskcoust(int i,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deskcoust)
{
    ba=i;
    // QString f=" ";
    // deskcoust::ip=this;
    ui->setupUi(this);
    QButtonGroup *bu=new QButtonGroup(this);
    bu->addButton(ui->pushButton);
    bu->addButton(ui->pushButton_2);
    bu->addButton(ui->pushButton_3);
    bu->addButton(ui->pushButton_9);
    bu->setExclusive(true);
    ui->label_17->setText(ac[i].name);
    ui->label_18->setText(ac[i].addrese);
    if(ac[i].ordercou.size()==0){
        ui->frame_23->setVisible(false);
    }
    else{
        ui->frame_23->setVisible(true);
    }
    if(ac[i].ordercou.size()==0){
        ui->label_22->setVisible(false);
    }
    else{
        ui->label_22->setVisible(true);
        QString a=QString::number(ac[i].ordercou.size());
        ui->label_22->setText(a);
    }
    if((ac[i].order).isEmpty()){
        ui->label_9->setVisible(false);
        ui->label_31->setVisible(true);
    }
    else{
        ui->label_31->setVisible(false);
        QString f="  ";
        ui->label_9->setVisible(true);
        QString ad=QString::number((ac[i].order).size());
        ui->label_9->setText(f+ad);
    }
    ui->lineEdit_9->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->comboBox_2->addItem("ALL SIDES");
    ui->comboBox_2->addItem("HIGHEST PRICE");
    ui->comboBox_2->addItem("LOWEST PRICE");
    ui->comboBox_2->addItem("RATE");
    ui->comboBox->addItem("All FOOD");
    ui->comboBox->addItem("HIGHEST PRICE");
    ui->comboBox->addItem("LOWEST PRICE");
    ui->comboBox->addItem("RATE");
    ui->comboBox->addItem("FAVORITE");
    ui->comboBox_2->setFixedHeight(51);
    ui->comboBox_2->setFixedWidth(61);
    ui->comboBox->setFixedHeight(51);
    ui->comboBox->setFixedWidth(61);
    ui->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ui->comboBox_2->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ui->stackedWidget->setCurrentIndex(0);
    ui->name->clear();
    ui->label_3->clear();
    ui->label_3->setText(ac[i].name);
    ui->name->setText(ac[i].name[0]);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&deskcoust::on_pushButton_3_clicked);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&deskcoust::buedi1);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&deskcoust::buedi2);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&deskcoust::buedi3);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&deskcoust::buedi4);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&deskcoust::logout);
}

deskcoust::~deskcoust()
{
    delete ui;
}

void deskcoust::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->page1li->clear();
    ui->page1li->setText(ac[ba].name);
    ui->lineEdit_2->setText(ac[ba].addrese);
    ui->lineEdit_3->setText(ac[ba].pass);
    ui->lineEdit_4->setText(ac[ba].id);
}

void deskcoust::buedi1(){

    if(!isedit1){
        isedit1=true;
        ui->page1li->setReadOnly(false);
    }
    else{
        isedit1=false;
        ui->page1li->setReadOnly(true);
        ac[ba].name=ui->page1li->text();
        (ac[ba].logview).push_back("The customer change name to "+ui->page1li->text());
        savecustomertofile();
        // QString f="   ";
        ui->name->clear();
        ui->name->setText(ac[ba].name[0]);
        ui->label_3->clear();
        ui->label_3->setText(ac[ba].name);
    }
}
void deskcoust::buedi2(){

    if(!isedit2){
        isedit2=true;
        ui->lineEdit_2->setReadOnly(false);
    }
    else{
        isedit2=false;
        ui->lineEdit_2->setReadOnly(true);
        ac[ba].addrese=ui->lineEdit_2->text();
        (ac[ba].logview).push_back("The customer change addrese to "+ui->lineEdit_2->text());
        savecustomertofile();
    }
}
void deskcoust::buedi3(){

    if(!isedit3){
        isedit3=true;
        ui->lineEdit_3->setReadOnly(false);
    }
    else{
        isedit3=false;
        ui->lineEdit_3->setReadOnly(true);
        ac[ba].pass=ui->lineEdit_3->text();
        (ac[ba].logview).push_back("The customer change password to "+ui->lineEdit_3->text());
        savecustomertofile();
    }
}
void deskcoust::buedi4(){

    if(!isedit4){
        isedit4=true;
        ui->lineEdit_4->setReadOnly(false);
    }
    else{
        isedit4=false;
        ui->lineEdit_4->setReadOnly(true);
        ac[ba].id=ui->lineEdit_4->text();
        (ac[ba].logview).push_back("The customer change id to "+ui->lineEdit_4->text());
        savecustomertofile();
    }
}

void deskcoust::logout()
{
    MainWindow *pagelog=new MainWindow();
    pagelog->show();
    this->hide();
}


void deskcoust::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->listWidget->setSpacing(3);
    ui->listWidget->clear();

    for (auto i = 0u; i < lifo.size(); i += 1) {
        bool isFavorite = false;

        for (auto j = 0u; j < ac[ba].favar.size(); j += 1) {
            if (ac[ba].favar[j].name == lifo[i].name) {
                isFavorite = true;
                break;
            }
        }

        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        cardfood *card = nullptr;

        if (isFavorite) {
            card = new cardfood(lifo[i].image, lifo[i].name, lifo[i].price, lifo[i].rate, lifo[i].mtn, ba, i, true, this);
            connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
        }
        else if(isFavorite==false && lifo[i].mtn!="") {
            card = new cardfood(lifo[i].image, lifo[i].name, lifo[i].price, lifo[i].rate, lifo[i].mtn, ba, i, this);
            connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
        }

        item->setSizeHint(QSize(1080, 274));
        ui->listWidget->setItemWidget(item, card);
    }
}


void deskcoust::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->page1li->clear();
    ui->page1li->setText(ac[ba].name);
    ui->lineEdit_2->setText(ac[ba].addrese);
    ui->lineEdit_3->setText(ac[ba].pass);
    ui->lineEdit_4->setText(ac[ba].id);
}


void deskcoust::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->listWidget_2->clear();
    for (auto j = 0u; j < ac[ba].favar.size(); j += 1) {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_2);
        cardfood *card = nullptr;
        card = new cardfood((ac[ba].favar)[j].image, (ac[ba].favar)[j].name, (ac[ba].favar)[j].price, (ac[ba].favar)[j].rate, (ac[ba].favar)[j].mtn, ba, j, true, this);
        connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
        item->setSizeHint(QSize(1080, 274));
        ui->listWidget_2->setItemWidget(item, card);
    }
}

void deskcoust::on_pushButton_13_clicked()
{
    QString tar = ui->lineEdit_5->text().trimmed();
    ui->listWidget_2->clear();
    for(auto i=0u;i<ac[ba].favar.size();i+=1){
        if((ac[ba].favar)[i].name==tar){
            QListWidgetItem *item = new QListWidgetItem(ui->listWidget_2);
            cardfood *card = nullptr;
            card = new cardfood((ac[ba].favar)[i].image, (ac[ba].favar)[i].name, (ac[ba].favar)[i].price, (ac[ba].favar)[i].rate, (ac[ba].favar)[i].mtn, ba, i, true, this);
            connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
            item->setSizeHint(QSize(1080, 274));
            ui->listWidget_2->setItemWidget(item, card);
            break;
        }
    }
}

void deskcoust::on_pushButton_10_clicked()
{
        QString tar = ui->lineEdit->text().trimmed();
        ui->listWidget->clear();


        if (tar.isEmpty()){
            return;}

        bool foundInFav=false;


        for (auto i = 0u; i < ac[ba].favar.size(); i += 1) {
            if ((ac[ba].favar)[i].name == tar) {
                QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
                cardfood *card = new cardfood((ac[ba].favar)[i].image,
                                              (ac[ba].favar)[i].name,
                                              (ac[ba].favar)[i].price,
                                              (ac[ba].favar)[i].rate,
                                              (ac[ba].favar)[i].mtn,
                                              ba, i, true, this);
                connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);

                item->setSizeHint(QSize(1080, 274));
                ui->listWidget->setItemWidget(item, card);

                foundInFav = true;
                break;
            }
        }


        if (!foundInFav) {
            for (auto i = 0u; i < lifo.size(); i += 1) {
                if (lifo[i].name == tar) {
                    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);


                    cardfood *card = new cardfood(lifo[i].image,
                                                  lifo[i].name,
                                                  lifo[i].price,
                                                  lifo[i].rate,
                                                  lifo[i].mtn,
                                                  ba, i, this);
                    connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);

                    item->setSizeHint(QSize(1080, 274));
                    ui->listWidget->setItemWidget(item, card);
                }
            }
        }
}
void deskcoust::up(){
    int size=ac[ba].order.size();
    ui->label_9->setVisible(true);
    QString ad=QString::number(size);
    ui->label_9->setText(ad);
}

void deskcoust::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->listWidget_4->clear();
    ui->label_24->clear();
    ui->lineEdit_6->clear();

    for(auto i = 0u; i < sili.size(); i += 1){
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_4);
        sidescard *card = new sidescard(sili[i].name, sili[i].price, sili[i].rate, sili[i].image, ba,i,true, this);
        connect(card, &sidescard::up, this, &deskcoust::refreshCardList);
        item->setSizeHint(QSize(358,398));
        ui->listWidget_4->setItemWidget(item, card);
    }

    refreshCardList();
}
double poy=0;
double tak=0;
bool flagth=false;
void deskcoust::refreshCardList()
{
    if((ac[ba].order).isEmpty()){
        ui->label_31->setVisible(true);
    }
    else{
        ui->label_31->setVisible(false);
    }
    ui->listWidget_3->clear();
    double pay=0;
    QHash<QString,FoodSummary> summaryMap;
    int totalItems=ac[ba].order.size();

    for (int i = 0; i < totalItems; ++i) {
        const classfood& food=ac[ba].order[i];
        double currentPrice=food.price.toDouble();
        summaryMap[food.name].count+=1;
        summaryMap[food.name].totalPrice=currentPrice;
        summaryMap[food.name].im=food.image;
    }

    for (auto it = summaryMap.constBegin(); it != summaryMap.constEnd(); ++it) {
        QString foodName=it.key();
        int total=it.value().count;
        QString image=it.value().im;
        QString finalPriceStr=QString::number(it.value().totalPrice);
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_3);
        ordercard *card=new ordercard(image, foodName, finalPriceStr, total, ba, this);
        connect(card, &ordercard::add, this, &deskcoust::refreshCardList);
        savecustomertofile();
        connect(card, &ordercard::rem, this, [=](){
            for (int i = 0; i < ac[ba].order.size();++i) {
                if (ac[ba].order[i].name == foodName) {
                    ac[ba].order.erase(ac[ba].order.begin()+i);
                    break;
                }
            }
            savecustomertofile();
            refreshCardList();
        });
        item->setSizeHint(QSize(321, 153));
        ui->listWidget_3->setItemWidget(item, card);
    }
    for(auto i=0u;i<ac[ba].order.size();i+=1){
        pay+=(ac[ba].order[i].price).toDouble();
    }
    poy=pay;
    if(flagth){
        pay-=tak;
        flagth=false;
        tak=0;
    }
    QString a=QString::number(pay);

    ui->label_11->setText(a);
    if(pay!=0){
        int size=ac[ba].order.size();
        ui->label_9->setVisible(true);
        QString ad=QString::number(size);
        ui->label_9->setText(ad);
    }
    else{
        ui->label_9->setVisible(false);
    }
}




void deskcoust::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->listWidget->setSpacing(3);
    ui->listWidget->clear();

    for (auto i = 0u; i < lifo.size(); i += 1) {
        bool isFavorite = false;

        for (auto j = 0u; j < ac[ba].favar.size(); j += 1) {
            if (ac[ba].favar[j].name == lifo[i].name) {
                isFavorite = true;
                break;
            }
        }

        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        cardfood *card = nullptr;

        if (isFavorite && lifo[i].mtn!="") {
            card=new cardfood(lifo[i].image, lifo[i].name, lifo[i].price, lifo[i].rate, lifo[i].mtn, ba, i, true, this);
            connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
        }
        else {
            card = new cardfood(lifo[i].image, lifo[i].name, lifo[i].price, lifo[i].rate, lifo[i].mtn, ba, i, this);
            connect(card->getbutton(),&QPushButton::clicked, this, &deskcoust::up);
        }
        item->setSizeHint(QSize(1080, 274));
        ui->listWidget->setItemWidget(item, card);
    }
}


void deskcoust::on_pushButton_16_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
    ui->listWidget_5->clear();
    for(auto i = 0u; i < sili.size(); i += 1){
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_5);
        sidescard *card = new sidescard(sili[i].name, sili[i].price, sili[i].rate, sili[i].image, ba,i,true, this);
        connect(card, &sidescard::up, this, &deskcoust::refreshCardList);
        item->setSizeHint(QSize(358,398));
        ui->listWidget_5->setItemWidget(item, card);
    }
}


void deskcoust::on_pushButton_14_clicked()
{
    if(ac[ba].order.size()!=0){
        QString gimat=ui->label_11->text();
        QString adad=gimat.left(3);
        QString asem="fody"+adad;
        QVector<classfood> nami=ac[ba].order;
        ui->label_9->setVisible(false);
        ac[ba].ordercou.push_back(orderco(gimat,nami));
        ac[ba].khod.push_back(code(asem));
        ac[ba].order.clear();
        ui->label_24->clear();
        QString cd=ui->lineEdit_6->text();
        if(cd.isEmpty()==false){
            for(auto i=0u;i<ac[ba].khod.size();i+=1){
                if(ac[ba].khod[i].name==cd){
                    ac[ba].khod.removeAt(i);
                    break;
                }
            }
        }
        refreshCardList();
        savecustomertofile();
        if(ac[ba].ordercou.size()>1){
            ui->label_22->setVisible(true);
            QString a=ui->label_22->text();
            int b=a.toInt();
            b+=1;
            QString ad=QString::number(b);
            ui->label_22->setText(ad);

        }
        else if(ac[ba].ordercou.size()==1){
            ui->label_22->setVisible(true);
            ui->label_22->setText("1");
        }
    }

}


void deskcoust::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->listWidget_6->clear();
    for(auto i = 0u; i < ac[ba].khod.size(); i += 1){
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_6);
        codecard *card = new codecard(ac[ba].khod[i].name, this);
        item->setSizeHint(QSize(350, 150));
        ui->listWidget_6->setItemWidget(item, card);
    }
}


void deskcoust::on_pushButton_15_clicked()
{
    QString kalme=ui->lineEdit_6->text();
    int in=-1;
    for(auto i=0u;i<ac[ba].khod.size();i+=1){
        if(ac[ba].khod[i].name==kalme){
            in=i;
        }
    }
    if(in!=-1){
        double ghim=(ui->label_11->text()).toDouble();
        if(ghim>(ac[ba].khod[in].mizan*100)){
            ui->label_24->clear();
            flagth=true;
            tak=ac[ba].khod[in].mizan*100;
            ui->label_24->setText("-"+QString::number(tak));
            refreshCardList();
            savecustomertofile();
            flagth=false;
        }
        else{
            ui->label_24->setText("minimum order value not met");
        }
    }
    else{
        ui->label_23->clear();
        ui->label_23->setText("No provide");
    }
}


void deskcoust::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->listWidget_9->clear();
    for(auto i=0u;i<ac[ba].ordercou.size();i+=1){
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_9);
        infocard *card = new infocard(ui->listWidget_8,i,ba,ac[ba].ordercou[i].value, this);
        item->setSizeHint(QSize(671, 189));
        ui->listWidget_9->setItemWidget(item, card);
    }
    if(ac[ba].ordercou.size()==0){
        ui->frame_23->setVisible(false);
    }
    else{
        ui->frame_23->setVisible(true);
    }
}


void deskcoust::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->listWidget->clear();
    QVector<classfood> FF=lifo;
    if(arg1!="FAVORITE"){
        if(arg1=="HIGHEST PRICE"){
            ui->lineEdit_8->setText("HIGHEST PRICE");
            std::sort(FF.begin(),FF.end(),[](const classfood &a,const classfood &b){
                return a.price.toDouble()>b.price.toDouble();
            });
        }
        else if(arg1=="LOWEST PRICE"){
            ui->lineEdit_8->setText("LOWEST PRICE");
            std::sort(FF.begin(),FF.end(),[](const classfood &a,const classfood &b){
                return a.price.toDouble()<b.price.toDouble();
            });
        }
        else if(arg1=="RATE"){
            ui->lineEdit_8->setText("RATE");
            std::sort(FF.begin(),FF.end(),[](const classfood &a,const classfood &b){
                return a.rate.toDouble()>b.rate.toDouble();
            });
        }
        else{
            ui->lineEdit_8->setText("All FOOD");
        }
        for (auto i = 0u; i < FF.size(); i += 1) {
            int originalIndex=-1;
            for (int k = 0; k < lifo.size(); ++k){
                if (lifo[k].name==FF[i].name) {
                    originalIndex=k; break; }
            }
            if (originalIndex==-1){
                originalIndex=i;
            }
            bool isFavorite = false;

            for (auto j = 0u; j < ac[ba].favar.size(); j += 1) {
                if (ac[ba].favar[j].name == FF[i].name) {
                    isFavorite = true;
                    break;
                }
            }

            QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            cardfood *card = nullptr;

            if (isFavorite && FF[i].mtn!="") {
                card = new cardfood(FF[i].image, FF[i].name, FF[i].price, FF[i].rate, FF[i].mtn, ba, originalIndex, true, this);
                connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
            }
            else {
                card = new cardfood(FF[i].image, FF[i].name, FF[i].price, FF[i].rate, FF[i].mtn, ba, originalIndex, this);
                connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
            }

            item->setSizeHint(QSize(1080, 274));
            ui->listWidget->setItemWidget(item, card);
        }
    }
    else{
        ui->lineEdit_8->setText("FAVORITE");
        for (auto j = 0u; j < ac[ba].favar.size(); j += 1) {
            QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            cardfood *card = nullptr;
            card = new cardfood((ac[ba].favar)[j].image, (ac[ba].favar)[j].name, (ac[ba].favar)[j].price, (ac[ba].favar)[j].rate, (ac[ba].favar)[j].mtn, ba, j, true, this);
            connect(card->getbutton(), &QPushButton::clicked, this, &deskcoust::up);
            item->setSizeHint(QSize(1080, 274));
            ui->listWidget->setItemWidget(item, card);
        }
    }
}


void deskcoust::on_comboBox_2_currentTextChanged(const QString &arg1){
    ui->listWidget_5->clear();
    QVector<sides>FS=sili;
    if(arg1=="HIGHEST PRICE"){
        ui->lineEdit_9->setText("HIGHEST PRICE");
        std::sort(FS.begin(),FS.end(),[](const sides &a,const sides &b){
            return a.price.toDouble()>b.price.toDouble();
        });
    }
    else if(arg1=="LOWEST PRICE"){
        ui->lineEdit_9->setText("LOWEST PRICE");
        std::sort(FS.begin(),FS.end(),[](const sides &a,const sides &b){
            return a.price.toDouble()<b.price.toDouble();
        });
    }
    else if(arg1=="RATE"){
        ui->lineEdit_9->setText("RATE");
        std::sort(FS.begin(),FS.end(),[](const sides &a,const sides &b){
            return a.rate.toDouble()>b.rate.toDouble();
        });
    }
    else{
        ui->lineEdit_9->setText("All SIDES");
    }
    for (auto i = 0u; i < FS.size(); i += 1) {
        int originalIndex = -1;
        for (int k = 0; k < sili.size(); ++k){
            if (sili[k].name == FS[i].name) {
                originalIndex = k;
                break;
            }
        }
        if (originalIndex == -1){
            originalIndex = i;
        }
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_5);
        sidescard *card = new sidescard(FS[i].name, FS[i].price, FS[i].rate, FS[i].image, ba,originalIndex,true, this);
        item->setSizeHint(QSize(358,398));
        ui->listWidget_5->setItemWidget(item, card);
    }
}

