#include "../../headers/List.h"


template<typename T>
inline std::ostream& operator<<(std::ostream &out, const List<T>& list) { return no_marks_list_out(out, list); }

inline std::ostream& operator<<(std::ostream &out, const List<unsigned char>& list) {return single_mark_list_out(out, list); }
inline std::ostream& operator<<(std::ostream &out, const List<char>& list) {return single_mark_list_out(out, list); }
