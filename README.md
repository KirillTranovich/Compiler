# Супер крутой проект ничего не делающего компилятора


## А как все это дело запускать
```
bison -d parser.y && flex lexer.l && g++ -c lex.yy.c parser.tab.c main.cpp -o prog
```
команда для компиляции всего(нужна если меняли бизоновский/флексовский файлик)
```
 g++ -c lex.yy.c parser.tab.c main.cpp -o prog
```
компиляция если меняли main  или( не дай бог) лезли в сгенерированные файлы
```
./prog.exe
```
исполняемый файлик
##  А как же сие творение выглядеть должно
```
root
|                     - something...
command---something -
|                     - something...
command---something...
|
emptyline
|
command
.
.
.
|
EOF
//это примерный пример того как я себе представляю структуру аст(... означает возможный пропуск дальнейших элементов)
```


## А как все плохо(версия для Арины)
(важно)в main.cpp *endroot(доступен сразу после выполнения функции yyparse()) - указатель на последний ast узел в файле... Почему не первый спросите вы меня?
Мне лень переделывать.. А если серьезно то просто переходя по ->prev пока -> prev != 0 вы спокойно дойдете и до первого...


### Памятка:  
конструкция (по опр) - цельная часть программы(команда, цикл, объявление и т.п.)
- У первой конструкции в файле тип root, у пустой строки состоящей из ; тип emptyline, y последней конструкции тип EOF, у остальных тип command. У всех конструкций в *next хранится следующая по порядку, в *prev - предыдущая. Если указатель равен нулю, значит их просто нет(это касается вообще люого указателя). У всех конструкций с типом command в left_child помещено то, что в этой конструкции лежит(обьявление класса, функции, цикл, выражение, уровень видимости, условие).

- lvl :  по сути {}, хранит в левом ребенке указатель на первую конструкцию в {}
- Name : хранит в *name свое имя и в левом ребенке указатель на тип, если тот есть
- type: собственно тип, родитель у него имя, и если тип не один(const int i в данном случае у i будет типо 2 типа int и const соответственно)
- Callfunk - есть имя и *arg - указатель на аргумент(вероятно последний)
- arg - собственно узил типа аргумент - его правым ребенком будет exp (см далее), next - cледующий аргумент, prev - предыдущий.
- arr_member - полная аналогия Callfunk, тип другой.(массив[args])
- ex_of_class : экземпляр класса. В args аргументы, в имени имя, в значении имя класса
- class : объявление класса в имени имя класса, в *in_level - указатель на первую/последнюю конструкцию в {} в args аргументы если есть...
- func: аналогично class
- conditionIF: есть in_level и *соnd - там ссылка на exp
- conditionELSE: то же но без cond
- FOR: есть in_level, cond, init, change
- While: то же, но без init, change
- exp: выражение в нем могут быть левый, правый зависимые ребенки, которые тоже выражения, и так по нему можно спускаться, пока ни левых ни правых не останется

!!Примечание, если что то является ребенком, то у него есть родитель. Если что то следующее для чего то, то наоборот у него есть предыдущий. Если это не так, то это баг

## А как все плохо(версия для Кирила)
1. комменты будут но я вряд ли закоментирую каждую строчку. Для лучшего понимания той дичи советую посмотреть памятку в разделе для Арины.
2. Что тебе делать?
   - разобраться с моим кодом(или удалить и написать свой, если мой совсем дерьмо)
   - наслаждаться жизнью
   - подописать доп функций(мы же вроде хотели язык для роботика сделать) или изменить что то в лучшую сторону если вдруг Арина, Степа, или кто еще попросит(например все char* было бы славно поменять на string)
   - спросить у Чубанова(мб нам будет нужнапрезентация и в любом случае нужно будет расписать возможности хотя этим уже наверное я займусь, впрочем из памятки большая их часть и так становится очевидна)

## А как все плохо( версия для Степы)
эээээ ну я до сих пор не знаю что делают тестировщики, ты можешь там проверить программу на надежность(пока что она с люой проблемой падает в segmentation fold) и поручить кирилу чделать ее более надежной. Для тебя(твоих тестов) мне надо(наверное) расписать все допустимые сценарии работы нашей программы ну или по крайней мере все допустимые конструкции в нашей программе и я черт возьми сделаю это(крайнюю меру, всеми возможными сценариями просто будем считать все те, что прошли тесты) но сделаю это по Форме Бэкуса — Наура, ибо так всем(мне) будет проще:
```
command:        
|command ';'           
|command new_class ';'  
|command cr_class ';'   
|command cr_func ';'    
|command exp ';'        
|command level  
|command cycle 
|command condition  
|command EF  
;

name: NAME 
|name NAME  
|name '('')'
| name '.' NAME   
| name '(' explist ')'  
| name '[' explist ']'    
;

new_class: name  '=' NEW name '(' explist ')'
|name  '=' NEW name '('  ')' 
;

cr_class: CLASS name'(' explist ')'  level 
|CLASS name '('  ')'   level            
;

cr_func: DEF name '(' explist ')' level     
|DEF name '('  ')' level           
;

condition: IF '(' exp ')'   level         
| ELSE   level                                 
;

cycle: FOR '('exp ';' exp ';' exp  ')'  level         
| FOR '('name ':' exp ')'   level                    
| WHILE '(' exp ')'     level                        
;

level: '{'command '}'
;

exp: exp CMP exp           
  | exp AND exp            
  | exp OR exp            
  | exp '+' exp           
  | exp '-' exp            
  | exp '*' exp            
  | exp '/' exp            
  | '(' exp ')'            
  | '-' exp %prec UMINUS                             
  | NUMBER                  
  | name '=' exp            
  | STRING          
  | name 
;

explist: exp
  | explist ',' exp 
;
```

## А что еще
89676718713 - есть предложения пожелания угрозы жизни или вопросы - пишите мне(а вдруг у кого то нет моего номера)
https://t.me/pppumpumnn - ну или так  
**а если серьезно предложения по структуре всего этого добра только приветствуются так как я в кой то веки со всем разобрался и сейчас легко могу вносить корректировки в код**

###### уголок нытика
<font size = 1>пачиму я бэкэндер ? зачем я все это делаю ? нихатю быть и бэкэндером и менеджером по продажам и ищо и тзсазаватььь....и еще и с...кто придумал этот с...я просто хочу повернуться к стеночке и поплакать(#яневтюрьметутможно) </font>

