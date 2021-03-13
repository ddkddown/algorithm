package main

type MyHashSet struct {
	table [1000001]int
}

func Constructor() MyHashSet {
	var set MyHashSet
	return set
}

func (this *MyHashSet) Add(key int) {
	this.table[key] = 1
}

func (this *MyHashSet) Remove(key int) {
	this.table[key] = 0
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
	return 1 == this.table[key]
}

/*
官方例子，用的链表+切片

const base = 769

type MyHashSet struct {
    data []list.List
}

func Constructor() MyHashSet {
    return MyHashSet{make([]list.List, base)}
}

func (s *MyHashSet) hash(key int) int {
    return key % base
}

func (s *MyHashSet) Add(key int) {
    if !s.Contains(key) {
        h := s.hash(key)
        s.data[h].PushBack(key)
    }
}

func (s *MyHashSet) Remove(key int) {
    h := s.hash(key)
    for e := s.data[h].Front(); e != nil; e = e.Next() {
        if e.Value.(int) == key {
            s.data[h].Remove(e)
        }
    }
}

func (s *MyHashSet) Contains(key int) bool {
    h := s.hash(key)
    for e := s.data[h].Front(); e != nil; e = e.Next() {
        if e.Value.(int) == key {
            return true
        }
    }
    return false
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/design-hashset/solution/she-ji-ha-xi-ji-he-by-leetcode-solution-xp4t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
