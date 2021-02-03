#include "mycrc.h"

myCRC::myCRC()
{



}

quint16 myCRC::crc_init()
{
    return 0xffff;
}

quint16 myCRC::crc_update(quint16 crc, QByteArray *data, int data_len)
{
    unsigned int tbl_idx;
    int i = 0;

    while (data_len--) {
      tbl_idx = ((crc >> 8) ^ data->at(i)) & 0xff;
      crc = (crc_table[tbl_idx] ^ (crc << 8)) & 0xffff;
      i++;
    }
    return crc & 0xffff;
}

quint16 myCRC::crc_finalize(quint16 crc)
{
    return crc;
}

