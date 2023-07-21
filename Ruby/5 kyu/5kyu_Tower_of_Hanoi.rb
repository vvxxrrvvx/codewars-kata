class Hanoi
  def initialize(n)
    @num_discs = n
  end
  
  def moves
    # Define the starting, auxiliary, and target pegs
    from_peg = 'A'
    to_peg = 'C'
    aux_peg = 'B'
    
    # Call the recursive helper function to solve the problem
    move_discs(@num_discs, from_peg, to_peg, aux_peg)
  end
  
  private
  
  def move_discs(num_discs, from_peg, to_peg, aux_peg)
    # Base case: if there's only one disc to move, do it and return
    if num_discs == 1
      return [[from_peg, to_peg]]
    end
    
    # Move num_discs - 1 discs from the from_peg to the aux_peg using the to_peg as auxiliary
    moves = move_discs(num_discs - 1, from_peg, aux_peg, to_peg)
    
    # Move the remaining disc from the from_peg to the to_peg
    moves << [from_peg, to_peg]
    
    # Move the num_discs - 1 discs from the aux_peg to the to_peg using the from_peg as auxiliary
    moves += move_discs(num_discs - 1, aux_peg, to_peg, from_peg)
    
    return moves
  end
end