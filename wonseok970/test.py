# -*- coding: utf-8 -*-
import pickle as pk


class idNotEnough(Exception):
    def __str__(self):
        return "ID Not Enough"


class PasswordNotEnough(Exception):
    def __str__(self):
        return "PW Not Enough"


try:
    id = input("아이디를 입력하세요 : ")
    if len(id) < 8:
        raise idNotEnough
    pw = input("비밀번호를 입력하세요 : ")
    if len(pw) < 8:
        raise PasswordNotEnough

except Exception as e:
    print(e)

account = {id: pw}

with open('dp.p', 'wb') as f:
    pk.dump(account, f)

with open('dp.p', 'rb') as f:
    data = pk.load(f)

print(data)
