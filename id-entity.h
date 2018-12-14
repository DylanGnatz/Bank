#ifndef ID_ENTITY_H_
#define ID_ENTITY_H_


class IDEntity {
private:
    static int _next_id;
    int _id;
public:
    IDEntity();
    int getID() const;
};

#endif /* ID_ENTITY_H_ */
