//
// @author: jiahong
// @date  : 19/05/18 4:43 PM
//

#ifndef AIMA_OPTIONAL_H
#define AIMA_OPTIONAL_H


namespace aima {

template<typename T>
class optional {
public:
    optional() = default;

    optional(const T &obj) : obj_(obj), filled_(true) {}

    T &if_not(T &alt) { return filled_ ? obj_ : alt; }

    const T &if_not(const T &alt) const { return filled_ ? obj_ : alt; }

    bool has_value() const { return filled_; }

    T &value() { return* *this; }

    const T &value() const { return * *this; }

    T &operator*() { return obj_; }

    const T &operator*() const { return obj_; }

    T *operator->() { return &obj_; }

    const T *operator->() const { return &obj_; }

    explicit operator bool() const { return filled_; }

private:
    T obj_;
    bool filled_ = false;
};

}       // end namespace aima

#endif //AIMA_OPTIONAL_H

