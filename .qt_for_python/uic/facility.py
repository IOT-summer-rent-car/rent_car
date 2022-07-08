# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/facility.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_facility(object):
    def setupUi(self, facility):
        facility.setObjectName("facility")
        facility.resize(732, 644)
        self.label = QtWidgets.QLabel(facility)
        self.label.setGeometry(QtCore.QRect(100, 20, 661, 17))
        self.label.setObjectName("label")
        self.pushButton = QtWidgets.QPushButton(facility)
        self.pushButton.setGeometry(QtCore.QRect(550, 40, 51, 25))
        self.pushButton.setObjectName("pushButton")
        self.lineEdit = QtWidgets.QLineEdit(facility)
        self.lineEdit.setGeometry(QtCore.QRect(100, 40, 451, 25))
        self.lineEdit.setObjectName("lineEdit")
        self.tableWidget = QtWidgets.QTableWidget(facility)
        self.tableWidget.setGeometry(QtCore.QRect(120, 100, 451, 441))
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(2)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        self.label_2 = QtWidgets.QLabel(facility)
        self.label_2.setGeometry(QtCore.QRect(210, 560, 91, 20))
        self.label_2.setText("")
        self.label_2.setObjectName("label_2")
        self.exit = QtWidgets.QPushButton(facility)
        self.exit.setGeometry(QtCore.QRect(300, 590, 89, 25))
        self.exit.setObjectName("exit")
        self.label_3 = QtWidgets.QLabel(facility)
        self.label_3.setGeometry(QtCore.QRect(310, 560, 151, 17))
        self.label_3.setObjectName("label_3")

        self.retranslateUi(facility)
        QtCore.QMetaObject.connectSlotsByName(facility)

    def retranslateUi(self, facility):
        _translate = QtCore.QCoreApplication.translate
        facility.setWindowTitle(_translate("facility", "Dialog"))
        self.label.setText(_translate("facility", "숙소 현황"))
        self.pushButton.setText(_translate("facility", "검색"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("facility", "숙소명"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("facility", "수용 인원"))
        self.exit.setText(_translate("facility", "돌아가기"))
        self.label_3.setText(_translate("facility", "숙소를 선택하였습니다."))
