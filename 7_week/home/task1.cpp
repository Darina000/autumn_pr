//  Created by Дарья Землянская on 20.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <utility>
 
struct Point{
    double x;
    double y;
};


class Figure {
    public:
        static const unsigned int count = 4;
        Point *array[count];
public:
        virtual double calc_square() const = 0;
        virtual double calc_perimeter() const = 0;
    
        virtual void Print() const = 0;
    friend std::ostream& operator<< (std::ostream &out, const Figure &figure);
};

std::ostream& operator<< (std::ostream &out, const Figure &figure){
    figure.Print();
    return out;
}


double distance(Point pair1, Point pair2) {
    double ans = sqrt(pow((pair1.x-pair2.x), 2)+pow((pair1.y-pair2.y), 2));
    return ans;
}

class Triangle: public Figure {
 
    public:
        double m_a, m_b, m_c;
 
    public:
        double calc_square() const {
            double m_p = (m_a + m_b + m_c)/2;
            return sqrt(m_p*(m_p - m_a) * (m_p - m_c) * (m_p - m_b));
        }
 
        double calc_perimeter() const {
            return m_a + m_b + m_c;
        }
    void Print() const{
        std::cout << "Side: "<< m_a << " " << m_b << " " << m_c << std::endl;
        std::cout << "Perimeter: " << calc_perimeter() << std::endl;
        std::cout << "Square: " << calc_square() << std::endl;
    }

    Triangle(Point a1, Point a2, Point a3, Point a4 = {0, 0}){
        
                array[0] = &a1;
                array[1] = &a2;
                array[2] = &a3;
        
                m_a = distance(*array[0], *array[1]);
                m_b = distance(*array[1], *array[2]);
                m_c = distance(*array[2], *array[0]);
            }
};
 

class Ellipce: public Figure {
 
    public:
        double a, b;
    public:
 
        double calc_square() const {
            return  M_PI * a * b;
        }
 
        double calc_perimeter() const {
            return 4 * (M_PI * a*b +(a-b)*(a-b))/(a+b);
        }
    
        void Print() const{
            std::cout << "Half-shafts: "<< a << " " << b << std::endl;
            std::cout << "Perimeter: " << calc_perimeter() << std::endl;
            std::cout << "Square: " << calc_square() << std::endl;
        }
    Ellipce(Point a1, Point a2, Point a3 = {0,0}, Point a4 = {0,0}){
                array[0] = &a1;
                array[1] = &a2;
                array[2] = &a3;
                array[3] = &a4;
        
                a = distance(*array[0], *array[2]);
                b = distance(*array[1], *array[3]);
    }
};



class Circle: public Ellipce {
private:
    double r;
    public:
        double calc_perimeter() const {
            return 2 * M_PI * r;
        }
        double calc_square() const {
            return  M_PI * a * b;
           }
        void Print() const{
            std::cout << "Radius: "<< r << std::endl;
            std::cout << "Perimeter: " << calc_perimeter() << std::endl;
            std::cout << "Square: " << calc_square() << std::endl;
        }
    Circle(Point a1, Point a2, Point a3 = {0,0}, Point a4 = {0,0}): Ellipce(a1, a2){
       r = distance(*array[0], *array[1]);;
    }
        
};



class Quadrangle: public Figure {
 
    public:
 
        double a, b, c, d;
 
    public:
 
        double calc_square() const {
            double m_q = distance(*array[0], *array[2]);
            double m_p1 = a + b + m_q;
            double m_p2 = c + d + m_q;
            double s1 = sqrt(m_p1 * (m_p1 - a) * (m_p1 - b) * (m_p1 - m_q));
            double s2 = sqrt(m_p2 * (m_p2 - c) * (m_p2 - d) * (m_p2 - m_q));
            return s1+s2;
        }
 
        double calc_perimeter() const {
            return a + b + c + d;
        }
        void Print() const{
            std::cout << "Side: "<< a << " " << b << " " << c << " " << d << std::endl;
            std::cout << "Perimeter: " << calc_perimeter() << std::endl;
            std::cout << "Square: " << calc_square() << std::endl;
        }

        Quadrangle(Point a1, Point a2, Point a3, Point a4){
            array[0] = &a1;
            array[1] = &a2;
            array[2] = &a3;
            array[3] = &a4;
            
            a = distance(*array[0], *array[1]);
            b = distance(*array[1], *array[2]);
            c = distance(*array[2], *array[3]);
            d = distance(*array[3], *array[0]);
        }
};

 
class Rectangle: public Quadrangle{
 
    public:
        double calc_square() const {
            return a * b;
        }
    Rectangle(Point a1, Point a2, Point a3 = {0,0}, Point a4 = {0,0}): Quadrangle(a1, a2, a3, a4){}
};
 
class Square: public Rectangle{
    public:
 
        double calc_perimeter() const {
            return 4 * a;
        }
    Square(Point a1, Point a2 = {0,0}, Point a3 = {0,0}, Point a4 = {0,0}): Rectangle(a1, a2, a3, a4){}
};
 



int main() {
    Point t1{0, 3};
    Point t2{0, 0};
    Point t3{4, 0};

    Point el_1{3, 0};
    Point el_2{0, 2};
    Point el_3{-3, 0};
    Point el_4{0, -2};

    Triangle triangle(t1, t2, t3);
    std::cout << triangle;
    Ellipce ellipce(el_1, el_2, el_3, el_4);
    std::cout << ellipce;
    Circle circle(el_1, el_2);
    std::cout << circle;
    Quadrangle quadrangle(el_1, el_2, el_3, el_4);
    std::cout << quadrangle;
    Rectangle rectangle(el_1, el_2, el_3, el_4);
    std::cout << rectangle;
    
    Figure *masssive[4] = { &triangle, &ellipce, &circle, &quadrangle};
    
}
