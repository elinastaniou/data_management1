#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "hp_file.h"
#include "record.h"

#define HP_ERROR -1;

#define BF_RECORDS_PER_BLOCK BF_BLOCK_SIZE/sizeof(Record); /* Το μέγεθος ενός record σε bytes */

#define CALL_BF(call)       \
{                           \
  BF_ErrorCode code = call; \
  if (code != BF_OK) {         \
    BF_PrintError(code);    \
    return HP_ERROR;        \
  }                         \
}

typedef struct {
  int lastBlockId;
  const int maxRec = BF_RECORDS_PER_BLOCK; /*BF_RECORD_SIZE/BF_BLOCK_SIZE*/
  int type;
} HP_info;

typedef struct {
  int numRec;
  BF_Block* lastBlock; 
} lastBlock;

int HP_CreateFile(char *fileName){
  int fd1;
  BF_Block* block;
  CALL_BF(BF_CreateFile(fileName));
  CALL_BF(BF_OpenFile(&fd1, fileName));
  CALL_BF(BF_Block_Init(&block));
  CALL_BF(BF_AllocateBlock(fd1, block));
  data = BF_Block_GetData(block);
  HP_info* fileInfo = data;
  fileInfo->lastBlockId = 0;
  fileInfo->type = 1; 
  return 1;
}

HP_info* HP_OpenFile(char *fileName, int *file_desc){
    HP_info* hpInfo;    
    return hpInfo;
}


int HP_CloseFile(int file_desc,HP_info* hp_info ){
}

int HP_InsertEntry(int file_desc,HP_info* hp_info, Record record){
    return -1;
}

int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    return -1;
}

