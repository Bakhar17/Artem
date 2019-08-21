import time
while True:
    i1=(input('Введите имя игрока 1:'))
    if i1!='STOP' and i1!='stop' and i1!='Stop':
        i2=(input('Введите имя игрока 2:'))
        import random
        m1=random.randint(1,4)
        m2=random.randint(1,4)
        d1=random.randint(6,14)
        d2=random.randint(6,14)
        kos=random.randint(1,4)
        if kos==m1 and kos!=m2:
            pob=i1
        elif kos==m2 and kos!=m1:
            pob=i2
        else:
            if m1>m2:
                pob=i1
            elif m1<m2:
                pob=i2
            else:
                if d1>d2:
                    pob=i1
                elif d1<d2:
                    pob=i2
                else:
                    pob='Ничья'
            if m2==1:
                m2='Черви'
            elif m2==2:
                m2="Бубна"
            elif m2==3:
                m2='Крест'
            else:
                m2='Пика'
            if d2==6:
                d2='Шестерка'
            elif d2==7:
                d2='Семерка'
            elif d2==8:
                d2='Восьмерка'
            elif d2==9:
                d2='Девятка'
            elif d2==10:
                d2='Десятка'
            elif d2==11:
                d2="Валет"
            elif d2==12:
                d2='Дама'
            elif d2==13:
                d2='Король'
            else:
                d2='Туз'
            if m1==1:
                m1='Черви'
            elif m1==2:
                m1="Бубна"
            elif m1==3:
                m1='Крест'
            else:
                m1='Пика'
            if d1==6:
                d1='Шестерка'
            elif d1==7:
                d1='Семерка'
            elif d1==8:
                d1='Восьмерка'
            elif d1==9:
                d1='Девятка'
            elif d1==10:
                d1='Десятка'
            elif d1==11:
                d1="Валет"
            elif d1==12:
                d1='Дама'
            elif d1==13:
                d1='Король'
            else:
                d1='Туз'
            if kos==1:
                kos='Черви'
            elif kos==2:
                kos="Бубна"
            elif kos==3:
                kos='Крест'
            else:
                kos='Пика'
            print('Козырь: ',kos)
            print('Карта игрока',i1,':','Достоинство:',d1,';','Масть:',m1)
            print('Карта игрока',i2,':','Достоинство:',d2,';','Масть:',m2)

            if pob==i1 or pob==i2:
                print('Победитель:',pob)
            else:
                print('Победителя нет:',pob)
    else:
        print('Стоп игра')
        time.sleep(1)
        print('Продолжить?',' ',end='',sep='')
        c=str(input())
        if c!='no':
            while c!='Yes' and c!='YES' and c!='yes':
                print('Продолжить?',' ',end='',sep='')
                c=str(input())
        else:
            break