//
// Created by iashi on 17.04.2022.
//

#ifndef SHOEGAZE2_MATRIX_H
#define SHOEGAZE2_MATRIX_H

#include <cmath>

namespace Shoegaze2
{
    class Matrix
    {
    private:
        // sx, shy, w0, shx, sy, w1, tx, ty, w2
        float m[3][3] {};
    public:
        Matrix()
        {
            m[0][0] = m[1][1] = m[2][2] = 1;
            m[0][1] = m[0][2] = m[1][0] = m[1][2] = m[2][0] = m[2][1] = 0;
        }

        Matrix(const float matrix[3][3])
        {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    m[i][j] = matrix[i][j];
        }

        Matrix(const float matrix[6])
        {
            m[0][0] = matrix[0];
            m[1][0] = matrix[1];
            m[0][1] = matrix[2];
            m[1][1] = matrix[3];
            m[0][2] = matrix[4];
            m[1][2] = matrix[5];
            m[2][0] = m[2][1] = 0;
            m[2][2] = 1;
        }

        Matrix(const Matrix& matrix)
        {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    m[i][j] = matrix.m[i][j];
        }

        float* operator[](int row)
        {
            if (row >= 0 && row < 3)
                return m[row];
            return nullptr;
        }

        Matrix & operator*=(const Matrix &matrix)
        {
            float mat[3][3] = {{0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}};
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    for (int k = 0; k < 3; k++)
                        mat[i][j] += m[i][k] * matrix.m[k][j];
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    m[i][j] = mat[i][j];
            return *this;
        }

        Matrix &operator*(const Matrix &matrix)
        {
            return operator*=(matrix);
        }

        Matrix & Translate(float tx, float ty)
        {
            *this *= Matrix().SetTranslate(tx, ty);
            return *this;
        }

        Matrix & Scale(float sx, float sy)
        {
            *this *= Matrix().SetScale(sx, sy);
            return *this;
        }

        Matrix & Scale(float sx, float sy, float px, float py)
        {
            *this *= (Matrix().SetTranslate(px, py) * Matrix().SetScale(sx, sy) * Matrix().SetTranslate(-px, -py));
            return *this;
        }

        Matrix & Rotate(float degrees)
        {
            *this *= Matrix().SetRotate(degrees);
            return *this;
        }

        Matrix & Rotate(float degrees, float px, float py)
        {
            *this *= (Matrix().SetTranslate(px, py) * Matrix().SetRotate(degrees) * Matrix().SetTranslate(-px, -py));
            return *this;
        }

        Matrix & SetTranslate(float tx, float ty)
        {
            m[0][2] = tx;
            m[1][2] = ty;
            return *this;
        }

        Matrix & SetScale(float sx, float sy)
        {
            m[0][0] = sx;
            m[1][1] = sy;
            return *this;
        }

        Matrix & SetRotate(float degrees)
        {
            float rads = degrees * 3.14159274101257324219f / 180.f;
            float sine = std::sin(rads);
            float cosine = std::cos(rads);
            m[0][0] = m[1][1] = cosine;
            m[0][1] = -sine;
            m[1][0] = sine;
            return *this;
        }
    };
}

#endif //SHOEGAZE2_MATRIX_H
