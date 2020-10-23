//  Created by Дарья Землянская on 20.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
 
struct Point{
    double x;
    double y;
};


class Figure {
public:
        Figure(const std::vector<Point>& arrr): aray(arrr) {
        }
        ~Figure(){};
    
        virtual double calc_square() const = 0;
        virtual double calc_perimeter() const = 0;
    
        friend std::ostream& operator<< (std::ostream &out, const Figure &figure);

protected:
        virtual void Print(std::ostream &out) const = 0;
    
    
private:
    std::vector <Point> aray;
};



std::ostream& operator<< (std::ostream &out, const Figure &figure){
    figure.Print(out);
    out<< std::endl;
    return out;
}

double distance(const Point &pair1, const Point &pair2) {
    return sqrt(pow((pair1.x-pair2.x), 2)+pow((pair1.y-pair2.y), 2));
}


class Triangle: public Figure {
    public:
        Triangle(const std::vector<Point>& arrr):Figure(arrr){
            m_a = distance(arrr[0], arrr[1]);
            m_b = distance(arrr[1], arrr[2]);
            m_c = distance(arrr[2], arrr[0]);
        }
        ~Triangle(){};
    
        double calc_square() const {
            double m_p = (m_a + m_b + m_c)/2;
            return sqrt(m_p*(m_p - m_a) * (m_p - m_c) * (m_p - m_b));
        }
 
        double calc_perimeter() const {
            return m_a + m_b + m_c;
        }
    
    protected:
        void Print(std::ostream &out) const{
            out << "Side: "<< m_a << " " << m_b << " " << m_c << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
        }
    private:
        double m_a, m_b, m_c;
};
 

class Ellipce: public Figure {
    public:
        Ellipce(const Point O, double o_a, double o_b = 0, const std::vector<Point>& arrr = {}):Figure(arrr), center(O), a(o_a), b(o_b){
        }
        ~Ellipce(){};
    
        double calc_square() const {
            return  M_PI * a * b;
        }
 
        double calc_perimeter() const {
            return 4 * (M_PI * a*b +(a-b)*(a-b))/(a+b);
        }
    protected:
        void Print(std::ostream &out) const{
            out << "Center: "<< center.x << " " << center.y << std::endl;
            out << "Half-shafts: "<< a << " " << b << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
        }
    private:
        const Point center;
        double a, b;
};



class Circle: public Ellipce {
    public:
        Circle(const Point O, double o_a): Ellipce(O, o_a), r(o_a), center(O){
        }
    
        ~Circle(){};
    
        double calc_perimeter() const {
            return 2 * M_PI * r;
        }
        double calc_square() const {
            return  M_PI * r * r;
           }
    protected:
        void Print(std::ostream &out) const{
            out << "Center: "<< center.x << " " << center.y << std::endl;
            out << "Radius: "<< r << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
        }
    private:
        const Point center;
        double r;
};



class Quadrangle: public Figure {
    public:
        Quadrangle(const std::vector<Point>& arrr):Figure(arrr){
            a = distance(arrr[0], arrr[1]);
            b = distance(arrr[1], arrr[2]);
            c = distance(arrr[2], arrr[3]);
            d = distance(arrr[3], arrr[0]);
            m_q = distance(arrr[0], arrr[2]);
        }
        ~Quadrangle(){};
    
        double calc_square() const {
            double m_p1 = a + b + m_q;
            double m_p2 = c + d + m_q;
            double s1 = sqrt(m_p1 * (m_p1 - a) * (m_p1 - b) * (m_p1 - m_q));
            double s2 = sqrt(m_p2 * (m_p2 - c) * (m_p2 - d) * (m_p2 - m_q));
            return s1+s2;
        }
 
        double calc_perimeter() const {
            return a + b + c + d;
        }
    protected:
        void Print(std::ostream &out) const{
            out << "Side: "<< a << " " << b << " " << c << " " << d << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
        }
    private:
           double a, b, c, d, m_q;
};

 
class Rectangle: public Quadrangle{
 
    public:
        Rectangle(const std::vector<Point>& arrr): Quadrangle(arrr){
            a = distance(arrr[0], arrr[1]);
            b = distance(arrr[1], arrr[2]);
        }
        ~Rectangle(){};
    
        double calc_square() const {
            return a * b;
        }
    private:
        double a, b;
};
 

class Square: public Rectangle{
    public:
        Square(const std::vector<Point>& arrr): Rectangle(arrr){
            a = distance(arrr[0], arrr[1]);
        }
        ~Square(){};
       double calc_perimeter() const {
            return 4 * a;
        }
    private:
        double a;
};
 



int main() {
    Point t1{0, 3};
    Point t2{0, 0};
    Point t3{4, 0};

    Point el_1{5, 1};
    Point el_2{-4, 2};
    Point el_3{-3, 0};
    Point el_4{0, -2};
    
    std::vector<Point> triang ={t1, t2, t3};
    std::vector<Point> quad ={el_1, el_2, el_3, el_4};
    std::vector<Point> rec ={t1, t2, t3, el_1};

    Triangle triangle(triang);
    std::cout << triangle;
    
    Ellipce ellipce(t2, 5, 7);
    std::cout << ellipce;
    
    Circle circle(t3, 5);
    std::cout << circle;
    
    Quadrangle quadrangle(quad);
    std::cout << quadrangle;
    
    Rectangle rectangle(rec);
    std::cout << rectangle;
    
    Figure *masssive[4] = { &triangle, &ellipce, &circle, &quadrangle};
    
}
