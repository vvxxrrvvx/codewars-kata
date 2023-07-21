class Node
	attr_accessor :data, :next
  def initialize(data)
  	@data = data
    @next = nil
  end
end

def length(node)
  count = 0
  while node
    count += 1
    node = node.next
  end
  count
end

def count(node, data)
  count = 0
  while node
    count += 1 if node.data == data
    node = node.next
  end
  count
end