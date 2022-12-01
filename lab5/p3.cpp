//
// Created by hung on 17.11.22.
//

#define make_string(s) str(s)
#define str(s) #s
#include make_string(./NAME/option.txt)
//html code
<!DOCTYPE html>
<html>
#include make_string(./LANGUAGE/header.txt)
<body>
#include make_string(./LANGUAGE/common_information.txt)
#include make_string(./LANGUAGE/auto_tuning.txt)
#include make_string(./LANGUAGE/fast_auto_tuning.txt)
#include make_string(./LANGUAGE/manual_tuning.txt)
#include make_string(./LANGUAGE/fast_frequency_tuning.txt)
#include make_string(./LANGUAGE/numeric_keypad_tuning.txt)
</body>
</html>