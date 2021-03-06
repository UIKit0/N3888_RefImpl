#include "drawing.h"
#include "xdrawinghelpers.h"
#include "xcairoenumhelpers.h"

using namespace std;
using namespace std::experimental::drawing;

path::path(const path_builder& pb)
: _Data(pb._Data)
, _Has_current_point(pb._Has_current_point)
, _Current_point(pb._Current_point)
, _Extents(pb.get_path_extents()) {
}

path::path(path&& other)
: _Data(move(other._Data))
, _Has_current_point(move(other._Has_current_point))
, _Current_point(move(other._Current_point))
, _Extents(move(other._Extents)) {
}

path& path::operator=(path&& other) {
	if (this != &other) {
		_Data = move(other._Data);
		_Has_current_point = move(other._Has_current_point);
		_Current_point = move(other._Current_point);
		_Extents = move(other._Extents);
	}
	return *this;
}

vector<path_data> path::get_data() const {
	return vector<path_data>(_Data);
}

const vector<path_data>& path::get_data_ref() const {
	return _Data;
}

rectangle path::get_path_extents() const {
	return _Extents;
}
