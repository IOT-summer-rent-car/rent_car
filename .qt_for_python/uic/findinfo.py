# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/findinfo.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_findinfo(object):
    def setupUi(self, findinfo):
        findinfo.setObjectName("findinfo")
        findinfo.resize(261, 212)
        self.label = QtWidgets.QLabel(findinfo)
        self.label.setGeometry(QtCore.QRect(40, 60, 67, 17))
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(findinfo)
        self.lineEdit.setGeometry(QtCore.QRect(110, 60, 113, 25))
        self.lineEdit.setObjectName("lineEdit")
        self.pushButton = QtWidgets.QPushButton(findinfo)
        self.pushButton.setGeometry(QtCore.QRect(80, 120, 89, 25))
        self.pushButton.setObjectName("pushButton")
        self.label_2 = QtWidgets.QLabel(findinfo)
        self.label_2.setGeometry(QtCore.QRect(60, 90, 141, 17))
        font = QtGui.QFont()
        font.setPointSize(8)
        self.label_2.setFont(font)
        self.label_2.setText("")
        self.label_2.setObjectName("label_2")

        self.retranslateUi(findinfo)
        QtCore.QMetaObject.connectSlotsByName(findinfo)

    def retranslateUi(self, findinfo):
        _translate = QtCore.QCoreApplication.translate
        findinfo.setWindowTitle(_translate("findinfo", "Dialog"))
        self.label.setText(_translate("findinfo", "이름 입력"))
        self.pushButton.setText(_translate("findinfo", "찾기"))
