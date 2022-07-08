# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/findbeach.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_findbeach(object):
    def setupUi(self, findbeach):
        findbeach.setObjectName("findbeach")
        findbeach.resize(982, 724)
        self.label = QtWidgets.QLabel(findbeach)
        self.label.setGeometry(QtCore.QRect(120, 50, 701, 17))
        self.label.setObjectName("label")

        self.retranslateUi(findbeach)
        QtCore.QMetaObject.connectSlotsByName(findbeach)

    def retranslateUi(self, findbeach):
        _translate = QtCore.QCoreApplication.translate
        findbeach.setWindowTitle(_translate("findbeach", "Dialog"))
        self.label.setText(_translate("findbeach", "TextLabel"))
