#include "RemoteFileItem.h"
#include "RemoteUserItem.h"
#include "ShareWindow.h"
#include "ShareUtils.h"

namespace beshare {

RemoteFileItem ::
RemoteFileItem(RemoteUserItem * owner, const char * fileName, const MessageRef & attrs)
  : _owner(owner), _fileName(fileName), _attributes(attrs)
{
   UpdateFields();
}

RemoteFileItem ::
~RemoteFileItem()
{
}

void
RemoteFileItem ::
UpdateFields()
{
   SetField(new BStringField(_fileName()), FILE_RESULT_COLUMN_FILENAME);

   char sizeBuf[64];
   sizeBuf[0] = '-';
   sizeBuf[1] = '\0';
   int64 s;
   if (_attributes.GetItemPointer()->FindInt64("beshare:File Size", &s) == B_NO_ERROR)
      GetByteSizeString(s, sizeBuf);
   SetField(new BStringField(sizeBuf), FILE_RESULT_COLUMN_SIZE);

   SetField(new BStringField(_owner->GetDisplayHandle()), FILE_RESULT_COLUMN_USER);
   SetField(new BStringField(_owner->GetBandwidthLabel()), FILE_RESULT_COLUMN_CONNECTION);

   const char * path = GetPath();
   SetField(new BStringField(path), FILE_RESULT_COLUMN_PATH);
}

const char *
RemoteFileItem ::
GetPath() const
{
   const char * ret;
   return (_attributes.GetItemPointer()->FindString("beshare:Path", &ret) == B_NO_ERROR) ? ret : "";
}

const char *
RemoteFileItem ::
GetInfo() const
{
   const char * ret;
   return (_attributes.GetItemPointer()->FindString("beshare:Info", &ret) == B_NO_ERROR) ? ret : "";
}

};  // end namespace beshare
