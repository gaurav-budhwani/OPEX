import re
import sys 

def generate_parsing_table(output_file):
    import re
    with open(output_file, 'r') as f:
        lines = f.readlines()

    table = {}
    terminals = set()
    non_terminals = set()
    
    current_state = -1
    in_state = False

    for line in lines:
        line = line.strip()
        m = re.match(r'^State (\d+)$', line)
        if m:
            current_state = int(m.group(1))
            table[current_state] = {}
            in_state = True
            continue
            
        if not in_state:
            continue
            
        if not line or line.startswith('//') or 'shift/reduce' in line or 'reduce/reduce' in line:
            continue
            
        m = re.match(r'^(\S+)\s+(.+)$', line)
        if m:
            sym, action = m.groups()
            if sym.startswith('$') and sym != '$default' and sym != '$end':
                continue
            if sym == '$accept' or sym == '$end' or '|' in sym or ':' in sym:
                continue
                
            table[current_state][sym] = action
            if 'go to state' in action:
                non_terminals.add(sym)
            else:
                if sym != '$default':
                    terminals.add(sym)

    terminals = sorted(list(terminals))
    non_terminals = sorted(list(non_terminals))
    
    headers = ['State'] + terminals + non_terminals
    print("," + ",".join(terminals + non_terminals))
    
    for i in sorted(table.keys()):
        row = [str(i)]
        for t in terminals:
            row.append(table[i].get(t, ""))
        for nt in non_terminals:
            # clean up go to state X
            val = table[i].get(nt, "")
            if 'go to state' in val:
                val = val.replace('go to state ', 'go ')
            row.append(val)
        print(",".join(f'"{x}"' for x in row))

if __name__ == "__main__":
    generate_parsing_table("parser.output")
