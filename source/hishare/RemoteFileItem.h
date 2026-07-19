#ifndef REMOTE_FILE_ITEM_H
#define REMOTE_FILE_ITEM_H

#include <interface/Bitmap.h>
#include <interface/ColumnListView.h>
#include <interface/ColumnTypes.h>
#include "util/Queue.h"
#include "message/Message.h"

#include "ShareConstants.h"

namespace beshare {

class RemoteUserItem;

enum {
   FILE_RESULT_COLUMN_FILENAME = 0,
   FILE_RESULT_COLUMN_SIZE,
   FILE_RESULT_COLUMN_USER,
   FILE_RESULT_COLUMN_CONNECTION,
   FILE_RESULT_COLUMN_PATH,
   NUM_FILE_RESULT_COLUMNS
};

class RemoteFileItem : public BRow
{
public:
   RemoteFileItem(RemoteUserItem * owner, const char * fileName, const MessageRef & attrs);
   ~RemoteFileItem();

   const char * GetFileName() const {return _fileName();}

   const Message & GetAttributes() const {return *_attributes.GetItemPointer();}

   RemoteUserItem * GetOwner() const {return _owner;}

   const char * GetPath() const;

   const char * GetInfo() const;

   void UpdateFields();

private:
   RemoteUserItem * _owner;
   String _fileName;
   MessageRef _attributes;
};

};  // end namespace beshare

#endif
