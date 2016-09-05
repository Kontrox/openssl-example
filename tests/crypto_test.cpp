#include "crypto.hpp"
#include <cassert>

using namespace std;

int main() {
  //MD5
  assert(Crypto::hex(Crypto::md5("Hei123")) == "91ae3539ed65d862f7cb841fdb332911");
  
  //SHA1
  // Results copied from https://caligatio.github.io/jsSHA/1
  assert(Crypto::hex(Crypto::sha1("Test")) == "640ab2bae07bedc4c163f679a746f7ab7fb5d1fa");
  assert(Crypto::hex(Crypto::sha1("Test", 2)) == "af31c6cbdecd88726d0a9b3798c71ef41f1624d5");
  
  //SHA256
  assert(Crypto::hex(Crypto::sha256("Hei123")) == "8715abf8cd7b62776e83bba97419ff8ddd7c35c96e04f48b92f4360f78399447");
  
  //SHA512
  assert(Crypto::hex(Crypto::sha512("Hei123")) == "0d78e16d7a933525dbbbeac796aae0b91769cdc42dcf8036456d125627b629963d2c03bfaf00ce2897c121f0be9de0071c3f782f84d86147aa31eb84f3b86391");
  
  // Results copied from http://www.freecodeformat.com/pbkdf2.php
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 4096, 128 / 8)) == "f66df50f8aaa11e4d9721e1312ff2e66");
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 8192, 512 / 8)) == "a941ccbc34d1ee8ebbd1d34824a419c3dc4eac9cbc7c36ae6c7ca8725e2b618a6ad22241e787af937b0960cf85aa8ea3a258f243e05d3cc9b08af5dd93be046c");
  assert(Crypto::hex(Crypto::pbkdf2("hash123", "Saltet til Ola", 2048)) == "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6" );
}
