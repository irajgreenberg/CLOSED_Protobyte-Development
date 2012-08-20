//
//  Vector3df.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Vector3df.h"
#include <iostream>
#include <math.h>


/*****************************************************/
/*                   Free Functions                  */
/*****************************************************/
Vector3df operator+(const Vector3df& lhs, const Vector3df& rhs)
// postcondition: returns lhs += rhs
{
    return Vector3df(lhs) += rhs;
}

Vector3df operator-(const Vector3df& lhs, const Vector3df& rhs)
// postcondition: returns lhs -= rhs
{
    return Vector3df(lhs) -= rhs;
}

Vector3df operator*(const Vector3df& lhs, const Vector3df& rhs)
// postcondition: returns lhs *= rhs
{
    return Vector3df(lhs) *= rhs;
}

Vector3df operator/(const Vector3df& lhs, const Vector3df& rhs)
// postcondition: returns lhs /= rhs
{
    return Vector3df(lhs) /= rhs;
}
/**************** End Free Functions *****************/


// initialize static counter
// keeps track of all the vectors created
int Vector3df::totalVectorCount = 0;


// constructor
Vector3df::Vector3df(float x, float y, float z):
x(x), y(y), z(z) {
    // increment static vector count
    totalVectorCount++;
}

// == operator for comparison of field data
bool Vector3df::operator==(const Vector3df& v) const {
    if (x == v.x && y == v.y && z == v.z){
        return true;
    }
    return false;
}

/*****************************************************/
/*                   Overloaded Ops                  */
/*****************************************************/
Vector3df& Vector3df::operator+=(const Vector3df& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3df& Vector3df::operator-=(const Vector3df& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3df& Vector3df::operator*=(const Vector3df& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vector3df& Vector3df::operator/=(const Vector3df& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}
/**************** End Overloaded Ops *****************/


// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Vector3df& vec) {
    output << "(" <<  vec.x << ", " << vec.y <<", " << vec.z <<")";
    return output;
}

// destructor
Vector3df::~Vector3df(){
    totalVectorCount--;
}

// copy constructor
Vector3df::Vector3df (const Vector3df& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    totalVectorCount++;
}

// assignment op
Vector3df& Vector3df::operator=(const Vector3df& vec) {
    if(*this == vec){
        return *this;
    }
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

// reference parameter
void Vector3df::add(const Vector3df& v){
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector3df::inv(){
    mult(-1);
}

void Vector3df::sub(const Vector3df& v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3df::mult(float val){
    x *= val;
    y *= val;
    z *= val;
}

void Vector3df::div(float val){
    mult(1.0/val);
}

void Vector3df::setTo(const Vector3df& v){
    x = v.x;
    y = v.y;
    z = v.z;
}

float Vector3df::mag(){
    float m = sqrt(x*x + y*y + z*z);
    return m;
}

void Vector3df::normalize(){
    float m = mag();
    div(m);
}

float Vector3df::angle(const Vector3df& v){
    // ====================================
    // USE Equation: a•b = |a||b|cosθ
    // 1. Get dot product: a•b
    // 2. Get magnitudes: |a||b|
    // 3. solve for theta
    //   θ = acos(a•b/|a||b|)
    // ====================================
    
    float d = dot(v);
    float am = mag();
    Vector3df b = v;
    float bm = b.mag();
    float ang = acosf(d/(am*bm));
    
    return ang;
}

float Vector3df::dot(const Vector3df& v){
    // copy vectors
    //Vector3df a = *this;
    //Vector3df b = v;
    
    //make unit vectors
    //a.normalize();
    //b.normalize();
    float d = x*v.x + y*v.y + z*v.z;
    return d;
    
}

void Vector3df::cross(const Vector3df& v, Vector3df& vCross){
    vCross.x = y*v.z - z*v.y;
    vCross.y = z*v.x - x*v.z;
    vCross.z = x*v.y - y*v.x;
}

float Vector3df::dist(const Vector3df& v){
    float dx = x-v.x;
    float dy = y-v.y;
    float dz = z-v.z;
    
    return sqrtf(dx*dx + dy*dy + dz*dz);
}

// static methods
Vector3df Vector3df::sub(Vector3df& v2, const Vector3df& v1) {
    return Vector3df(v2.x-v1.x, v2.y-v1.y, v2.z-v1.z);
}

Vector3df Vector3df::add(Vector3df& v1, float val) {
    return Vector3df(v1.x+val, v1.y+val, v1.z+val);
}


Vector3df Vector3df::mult(Vector3df& v1, float val) {
    return Vector3df(v1.x*val, v1.y*val, v1.z*val);
}

// inspired/ported from C4 Vector4D api
Vector3df& Vector3df::RotateAroundAxis(float theta, const Vector3df& axis) {
    float s = sinf(theta);
    float c = cosf(theta);
    float k = 1.0 - c;
    
    float tempX = x * (c + k * axis.x * axis.x) + y * (k * axis.x * axis.y - s * axis.z)
    + z * (k * axis.x * axis.z + s * axis.y);
    float tempY = x * (k * axis.x * axis.y + s * axis.z) + y * (c + k * axis.y * axis.y)
    + z * (k * axis.y * axis.z - s * axis.x);
    float tempZ = x * (k * axis.x * axis.z - s * axis.y) + y * (k * axis.y * axis.z + s * axis.x)
    + z * (c + k * axis.z * axis.z);
    
    x = tempX;
    y = tempY;
    z = tempZ;
    
    return (*this);
}




// getters/setters
void Vector3df::setX(float x){
    this->x = x;
}

float Vector3df::getX() {
    return x;
}

void Vector3df::setY(float y){
    this->y = y;
    
}

float Vector3df::getY() const {
    return y;
}

void Vector3df::setZ(float z){
    this->z = z;
}

float Vector3df::getZ() {
    return z;
}

float Vector3df::getNormX(){
    return normX;
}

void Vector3df::setNormX(float normX){
    this->normX = normX;
}

float Vector3df::getNormY(){
    return normY;
}

void Vector3df::setNormY(float normY){
    this->normY = normY;
}

float Vector3df::getNormZ(){
    return normZ;
}

void Vector3df::setNormZ(float normZ){
    this->normZ = normZ;
}



