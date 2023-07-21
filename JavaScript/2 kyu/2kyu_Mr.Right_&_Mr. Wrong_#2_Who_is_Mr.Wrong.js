function findOutMrWrong(conversation){
  const regs = [/(\S+?):I'm in (\d+)(?:st|nd|rd|th) position\./,
                /(\S+?):There (?:are|is) (\d+) people behind me\./,
                /(\S+?):There (?:are|is) (\d+) people in front of me\./,
                /(\S+?):The man behind me is (\S+?)\./,
                /(\S+?):The man in front of me is (\S+?)\./,];
  const info = {};
  const result = [];
  conversation.forEach(v=>{
    const [t, [,person, data]] = regs.reduce((a,c,i)=>a[1]?a:[i,v.match(c)], []);
    info[person] = (info[person]||[]).concat([[t, data]]);
  });
  const people = Object.keys(info);
  for (let i=0; i<people.length; i++) { 
    const order = Array(people.length);
    const waiting = {}; 
    function insertPerson(person, index, refOrder=order, refWaiting=waiting) {
      index = Number(index);
      if (![-1, index].includes(refOrder.indexOf(person))
          || index < 0
          || index > refOrder.length
          || ![undefined, person].includes(refOrder[index])) {
        throw new Error('Not Mr. Wrong!');
      }
      refOrder[index] = person;
      const {before, after} = refWaiting[person] || {};
      refWaiting[person] = undefined;
      if (before) insertPerson(before, index-1, refOrder, refWaiting);
      if (after) insertPerson(after, index+1, refOrder, refWaiting);
    }
    function setWaiting(before, after) {
      const [bi, ai] = [waiting[before] || {}, waiting[after] || {}];
      if ((bi.after && bi.after != after) || (ai.before && ai.before != before)) {
        throw new Error("Not Mr. Wrong!");
      }
      bi.after = after;
      ai.before = before;
      waiting[before] = bi;
      waiting[after] = ai;
    }
    try {
      for (const person of people) {
        if (person == people[i]) continue; 
        for (const [infoType, data] of info[person]) {
          if (infoType === 0) insertPerson(person, data-1);
          else if (infoType === 1) insertPerson(person, people.length-data-1);
          else if (infoType === 2) insertPerson(person, data);
          else if (infoType === 3) {
            const [posF, posB] = [order.indexOf(person), order.indexOf(data)];
            if (posB > -1) insertPerson(person, posB-1);
            else if (posF > -1) insertPerson(data, posF+1);
            else setWaiting(person, data);
          } else {
            const [posF, posB] = [order.indexOf(data), order.indexOf(person)];
            if (posB > -1) insertPerson(data, posB-1);
            else if (posF > -1) insertPerson(person, posF+1);
            else setWaiting(data, person);
          }
        }
      }
      function fitRemainders(tempOrder, tempWaiting) {
        if (tempOrder.every(v=>v)) {
          const [liarInfo, liar] = [info[people[i]], people[i]];
          if (liarInfo.every(([infoType, data])=>{
            if (infoType == 0 && tempOrder[data-1] == liar) return false;
            if (infoType == 1 && tempOrder[people.length-data-1] == liar) return false;
            if (infoType == 2 && tempOrder[data] == liar) return false;
            if (infoType == 3 && tempOrder[tempOrder.indexOf(liar)+1] == data) return false;
            if (infoType == 4 && tempOrder[tempOrder.indexOf(liar)-1] == data) return false;
            return true;
          })) {
            if (!result.includes(liar)) result.push(liar);
            throw new Error("Found liar, check if other possibilities exist");
          }
        }
        for (const person of people) {
          if (tempOrder.includes(person)) continue;
          for (let pos=0; pos<tempOrder.length; pos++) {
            if (tempOrder[pos]) continue;
            const [refOrder, refWaiting] = [[...tempOrder], JSON.parse(JSON.stringify(tempWaiting))]
            try {
              insertPerson(person, pos, refOrder, refWaiting);
              const res = fitRemainders(refOrder, refWaiting);
              if (res) return res;
            } catch (_) {
              if (result.length > 1) return null;
            }
          }
        }
      }
      const res = fitRemainders([...order], JSON.parse(JSON.stringify(waiting)));
      if (res) return res;
    } catch (_) {
      if (result.length > 1) return null;
    }
  }
  return (new Set(result)).size == 1 ? result[0] : null;
}