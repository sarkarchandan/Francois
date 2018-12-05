#ifndef MATRIX_ELEMENT_PROTOCOL
#define MATRIX_ELEMENT_PROTOCOL

namespace algebra
{
  struct MatrixElementProtocol
  {
    virtual const MatrixElementProtocol& operator +(const MatrixElementProtocol& _other) = 0;
    virtual const MatrixElementProtocol& operator -(const MatrixElementProtocol& _other) = 0;
    virtual const MatrixElementProtocol& operator *(const MatrixElementProtocol& _other) = 0;
  };
} // algebra

#endif //MATRIX_ELEMENT_PROTOCOL