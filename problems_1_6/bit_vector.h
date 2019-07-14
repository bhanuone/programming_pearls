#include <iostream>

#define WORD_SIZE 32
#define BITS_WS 5
#define MASK 0x1f

namespace devstacks {
  class BitVector {
    private:
      unsigned int * bv_;
      size_t bvSize_;

      size_t BucketNumber (size_t index) const;
      unsigned int Mask   (size_t index) const;
    public:
      void Set      (size_t index); // make index bit = 1
      void Set      ();             // make all bits = 1
      void Unset    (size_t index); // make index bit = 0
      void Unset    ();             // make all bits = 0
      void Flip     (size_t index); // flip index bit
      void Flip     ();             // change all bits
      int Test     (size_t index) const; // return index bit value

      explicit BitVector(size_t);
               BitVector(const BitVector&);
               ~BitVector();
      BitVector& operator = (const BitVector& a);  // assignment operator

      size_t Size () const;         // returns size of bit vector
  };


  size_t BitVector::BucketNumber(size_t index) const {
    index >>= BITS_WS;
    if (index > bvSize_) {
      std::cerr << "** BitVector error: index out of range\n";
      exit (EXIT_FAILURE);
    }
    return index;
  }

  unsigned int BitVector::Mask (size_t index) const {
    return (0x01 << (index & MASK));
  }

  BitVector::BitVector(size_t numbits) {
    bvSize_ = (numbits / WORD_SIZE) + 1;
    bv_ = new unsigned int [bvSize_];
    if (bv_ == 0) {
      std::cerr << "** BitVector memory allocation failure -- terminating program.\n";
      exit (EXIT_FAILURE);
    }
    for (int i = 0; i < bvSize_; i++) {
      bv_[i] = 0x00;
    }
  }

  BitVector::~BitVector() {
    delete bv_;
  }

  BitVector& BitVector::operator = (const BitVector& bitv) {  // assignment operator
    if (this != &bitv) {
      if (bvSize_ != bitv.bvSize_) {
        delete [] bv_;
        bvSize_ = bitv.bvSize_;
        bv_ = new unsigned int [bvSize_];
        if (bv_ == 0) {
          std::cerr << "** BitVector memory allocation failure -- terminating program.\n";
          exit (EXIT_FAILURE);
        }
      }
      for (size_t i = 0; i < bvSize_; ++i)
        bv_[i] = bitv.bv_[i];
    }
    return *this;
  }

  void BitVector::Set(size_t index) {
    bv_[BucketNumber(index)] |= Mask(index);
  }

  void BitVector::Unset(size_t index) {
    bv_[BucketNumber(index)] |= Mask(index);
  }

  void BitVector::Unset() {
    for (size_t i = 0; i < bvSize_; ++i)
        bv_[i] = 0x00;
  }

  void BitVector::Flip(size_t index) {
    bv_[BucketNumber(index)] ^= Mask(index);
  }


  int BitVector::Test(size_t index) const {
    return 0 != (bv_[BucketNumber(index)] & Mask(index));
  }


}

