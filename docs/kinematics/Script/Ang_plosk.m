clear, clc;
syms x_a2 y_a2 z_a2 x y z x1 y1 z1 x2 y2 z2 x3 y3 z3 x_m y_m z_m
disp('x_a2 y_a2 z_a2 - координаты желаемой точки, x_m y_m z_m - координаты локтя')
disp ' '
M = [(x - x1) (x2 - x1) (x3 - x1);... %Матрица содержащая обобщённые координаты плоскости 
    (y - y1) (y2 - y1) (y3 - y1);...  %и координаты трёх точек, по которым строится плоскость
    (z - z1) (z2 - z1) (z3 - z1)];
M1 = subs(M, {x1, y1, z1, x2, y2, z2, x3, y3, z3}, [0, 0, 0, x_m, y_m, 0, x_a2, y_a2, z_a2]);%Подстановка наших точек(начало координат, координата локтя, желаемая точка)
disp('Уравнение желаемой плоскости:')
xyz_1 = det(M1);%Находим уравнение плоскости через определитель матрицы
disp(xyz_1)
disp('Координаты нормали к желаемой плоскости:')
x_n1 = subs(xyz_1, {x, y, z}, [1, 0, 0]);%Находим координаты нормали к плоскости как коэффициенты стоящие перед
y_n1 = subs(xyz_1, {x, y, z}, [0, 1, 0]);%обобщёнными координатами в уравнении плоскости. Для этого одну координату
z_n1 = subs(xyz_1, {x, y, z}, [0, 0, 1]);%делаем = 1, остальные = 0, учитывая что у нас нет свободного члена(D = 0)
disp(x_n1)
disp(y_n1)
disp(z_n1)
x_n2 = 0; %Координаты нормали к плоскости XY(нормаль совпадает с осью Z)
y_n2 = 0;
z_n2 = 1;
disp('Косинус угла между исходной(XY)и желаемой плоскостями:')
cos_ang = ((x_n1*x_n2 + y_n1*y_n2 + z_n1*z_n2))/(sqrt(x_n1^2 + y_n1^2 + z_n1^2)*sqrt(x_n2^2 + y_n2^2 + z_n2^2))%Формула косинуса угла между плоскостями
