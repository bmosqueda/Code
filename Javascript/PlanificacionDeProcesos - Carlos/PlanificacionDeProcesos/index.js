let btnGenerate = document.getElementById('generate'),
  btnCalculate = document.getElementById('calculate')
  select = document.getElementById('algorithm'),
  colQuantum = document.getElementById('colQuantum'),
  processes = null,
  quantity = 0,
  maxTime = 0;

select.addEventListener('change', (ev) => {
  if (select.selectedIndex != 4) {
    if (!colQuantum.classList.contains('is-hidden'))
      colQuantum.classList.add('is-hidden')
  } else {
    if (colQuantum.classList.contains('is-hidden'))
      colQuantum.classList.remove('is-hidden')
  }
})

btnGenerate.addEventListener('click', function(ev) {
  quantity = parseInt(document.getElementById('numberOfProcess').value)
  maxTime = parseInt(document.getElementById('maximDuration').value)

  if (quantity > 0 && maxTime > 0)
    processes = createProcesses(quantity, maxTime)
  else
    return

  let table = document.getElementById('tableProcesses')
  while (table.hasChildNodes())
    table.removeChild(table.firstChild)

  for(var i = 0, length = processes.length; i < length; i++) {
    let row = document.createElement('tr')
    let pid = document.createElement('th')
    pid.textContent = processes[i].pid
    let name = document.createElement('td')
    name.textContent = processes[i].name
    let time = document.createElement('td')
    time.textContent = processes[i].time
    row.appendChild(pid)
    row.appendChild(name)
    row.appendChild(time)
    table.appendChild(row)
  }
  let columnsRes = document.getElementById('result')
  if (!columnsRes.classList.contains('is-hidden')) {
      columnsRes.classList.add('is-hidden')
      document.getElementById('chartContainer').style.visibility = "hidden"
  }
  if (!document.getElementById('msg').classList.contains('is-hidden'))
    document.getElementById('msg').classList.add('is-hidden')
})

btnCalculate.addEventListener('click', (ev) => {
  let method = select.selectedIndex, result = null
  if (processes == null) {
    document.getElementById('msg').classList.remove('is-hidden')
    return
  }
  if (method != 4) {
    if (method == 1) {
      result = firstComeFirstServed(processes)
      console.log(result)
    } else if (method == 2) {
      result = shortestJobFirst(processes)
      console.log(result)
    } else if (method == 3) {
      result = largestJobFirst(processes)
      console.log(result)
    }
  } else {
    let quantum = parseInt(document.getElementById('quantum').value)
    if (quantum > 0 && quantum <=  maxTime) {
      result = roundRobin(processes, quantum)
      console.log(result)
    } else
      return
  }
  let cols = document.getElementById('result'),
    tableBody = document.getElementById('tableResult')
  while (tableBody.hasChildNodes())
    tableBody.removeChild(tableBody.firstChild)
  for(var i = 0; i < result.processes.length; i++) {
    let row = document.createElement('tr')
    let pid = document.createElement('th')
    pid.textContent = result.processes[i].pid
    let name = document.createElement('td')
    name.textContent = result.processes[i].name
    let wait = document.createElement('td')
    wait.textContent = result.processes[i].wait
    let response = document.createElement('td')
    response.textContent = result.processes[i].response
    row.appendChild(pid)
    row.appendChild(name)
    row.appendChild(wait)
    row.appendChild(response)
    tableBody.appendChild(row)
  }
  
  document.getElementById('cmax').textContent = result.Cmax
  document.getElementById('wait').textContent = result.wait.toFixed(4)
  document.getElementById('response').textContent = result.response.toFixed(4)

  if (method != 4)
    processesChart(result.processes)
  else
    processesChart(result.subprocesses, parseInt(document.getElementById('quantum').value))

  if (cols.classList.contains('is-hidden')) {
    cols.classList.remove('is-hidden')
    document.getElementById('chartContainer').style.visibility = "visible"
  }
})

/**
 * 
 * @param {Number} quantity 
 * @param {Number} maxTime 
 */
function createProcesses(quantity, maxTime) {
  var processes = []
  for (var i = 0; i < quantity; i++) {
    let process = {
      name: verbs[Math.floor(Math.random() * 634)],
      // pid: Math.floor(Math.random() * 11001) + 1,
      pid: i + 1,
      time: Math.floor(Math.random() * (maxTime + 1)) + 1,
      color: colors[Math.floor(Math.random() * 133)].hex
    }
    processes.push(process)
  }
  return processes
}

/**
 * @param {Array} processes 
 */
function firstComeFirstServed(processes) {
  let time = 0, wait = 0, response = 0, length = processes.length
  for (var i = 0; i < length; i++) {
    processes[i].wait = time
    wait += processes[i].wait
    processes[i].response = (time += processes[i].time)
    response += processes[i].response
  }
  return {
    processes: processes,
    wait: wait / length,
    response: response / length,
    Cmax: processes[length - 1].response
  }
}

/**
 * @param {Array} processes
 */
function shortestJobFirst(processes) {
  copy = Array.from(processes)
  copy.sort((a, b) => {
    return a.time - b.time
  })
  return firstComeFirstServed(copy)
}

/**
 * @param {Array} processes
 */
function largestJobFirst(processes) {
  copy = Array.from(processes)
  copy.sort((a, b) => {
    return b.time - a.time
  })
  return firstComeFirstServed(copy)
}

/**
 * @param {Array} processes
 */
function roundRobin(processes, quantum) {
  let copy = [],
    subdivision = 0,
    step = 0,
    subprocesses = [],
    wait = [],
    response = [],
    length = processes.length;
  for(var i = 0; i < processes.length; i++) {
    copy.push(Object.assign({}, processes[i]))
    subdivision += Math.ceil(processes[i].time / quantum)
  }
  while(subprocesses.length < subdivision) {
    for(var i = 0; i < length; i++) {
      if(copy[i].time > 0) {
        if(copy[i].time > quantum) {
          let process = Object.assign({},copy[i])
          process.time = quantum
          subprocesses.push(process)
          copy[i].time -= quantum
        } else {
          let process = Object.assign({},copy[i])
          process.time = copy[i].time
          subprocesses.push(process)
          copy[i].time = 0
        }
      }
    }
  }
  let time = 0
  for(var i = 0; i < subprocesses.length; i++) {
    subprocesses[i].wait = time
    subprocesses[i].response = (time += subprocesses[i].time)
  }
  copy = Array.from(processes)
  for(var i = 0; i < length; i++) {
    let allSub = subprocesses.filter(e => e.pid === copy[i].pid);
    let sum = 0, waited = 0
    for(var j = 0; j < allSub.length; j++) {
      sum += (allSub[j].wait - waited)
      waited = allSub[j].response
    }
    wait.push(sum)
    response.push(allSub[allSub.length - 1].response)
    copy[i].wait = sum
    copy[i].response = allSub[allSub.length - 1].response
  }
  return {
    processes: copy,
    subprocesses: subprocesses,
    wait: wait.reduce((a,b) => a + b) / length,
    response: response.reduce((a,b) => a + b) / length,
    Cmax: response.reduce((a,b) => Math.max(a,b))
  }
}

function processesChart(processes, quantum = 5) {
  let data = getDataChart(processes)
  console.log(data)
  var chart = new CanvasJS.Chart("chartContainer", {
    animationEnabled: true,
    exportEnabled: true,
    title: {
      text: "Asignación de CPU"
    },
    axisX: {
      title: "Proceso"
    },
    axisY: {
      includeZero: true,
      title: "Tiempo",
      interval: quantum,
    }, 
    data: [{
      type: "rangeBar",
      showInLegend: true,
      yValueFormatString: "#0",
      indexLabel: "{y[#index]}",
      legendText: "Timpo de ejecución",
      toolTipContent: "<b>{label}</b>: {y[0]} to {y[1]}",
      dataPoints: data
    }]
  });
  chart.render();
}

function getDataChart(processes, quantum = 5) {
  let data = []
  for(var i = 0; i < processes.length; i++) {
    data.push({
      x: i,
      y: [
        processes[i].wait,
        processes[i].response
      ],
      label: processes[i].pid + " " + processes[i].name,
      color: processes[i].color
    })
    console.log(data)
  }
  return data
}

const verbs =[
    "accept",
    "add",
    "admire",
    "admit",
    "advise",
    "afford",
    "agree",
    "alert",
    "allow",
    "amuse",
    "analyse",
    "announce",
    "annoy",
    "answer",
    "apologise",
    "appear",
    "applaud",
    "appreciate",
    "approve",
    "argue",
    "arrange",
    "arrest",
    "arrive",
    "ask",
    "attach",
    "attack",
    "attempt",
    "attend",
    "attract",
    "avoid",
    "back",
    "bake",
    "balance",
    "ban",
    "bang",
    "bare",
    "bat",
    "bathe",
    "battle",
    "beam",
    "beg",
    "behave",
    "belong",
    "bleach",
    "bless",
    "blind",
    "blink",
    "blot",
    "blush",
    "boast",
    "boil",
    "bolt",
    "bomb",
    "book",
    "bore",
    "borrow",
    "bounce",
    "bow",
    "box",
    "brake",
    "branch",
    "breathe",
    "bruise",
    "brush",
    "bubble",
    "bump",
    "burn",
    "bury",
    "buzz",
    "calculate",
    "call",
    "camp",
    "care",
    "carry",
    "carve",
    "cause",
    "challenge",
    "change",
    "charge",
    "chase",
    "cheat",
    "check",
    "cheer",
    "chew",
    "choke",
    "chop",
    "claim",
    "clap",
    "clean",
    "clear",
    "clip",
    "close",
    "coach",
    "coil",
    "collect",
    "colour",
    "comb",
    "command",
    "communicate",
    "compare",
    "compete",
    "complain",
    "complete",
    "concentrate",
    "concern",
    "confess",
    "confuse",
    "connect",
    "consider",
    "consist",
    "contain",
    "continue",
    "copy",
    "correct",
    "cough",
    "count",
    "cover",
    "crack",
    "crash",
    "crawl",
    "cross",
    "crush",
    "cry",
    "cure",
    "curl",
    "curve",
    "cycle",
    "dam",
    "damage",
    "dance",
    "dare",
    "decay",
    "deceive",
    "decide",
    "decorate",
    "delay",
    "delight",
    "deliver",
    "depend",
    "describe",
    "desert",
    "deserve",
    "destroy",
    "detect",
    "develop",
    "disagree",
    "disappear",
    "disapprove",
    "disarm",
    "discover",
    "dislike",
    "divide",
    "double",
    "doubt",
    "drag",
    "drain",
    "dream",
    "dress",
    "drip",
    "drop",
    "drown",
    "drum",
    "dry",
    "dust",
    "earn",
    "educate",
    "embarrass",
    "employ",
    "empty",
    "encourage",
    "end",
    "enjoy",
    "enter",
    "entertain",
    "escape",
    "examine",
    "excite",
    "excuse",
    "exercise",
    "exist",
    "expand",
    "expect",
    "explain",
    "explode",
    "extend",
    "face",
    "fade",
    "fail",
    "fancy",
    "fasten",
    "fax",
    "fear",
    "fence",
    "fetch",
    "file",
    "fill",
    "film",
    "fire",
    "fit",
    "fix",
    "flap",
    "flash",
    "float",
    "flood",
    "flow",
    "flower",
    "fold",
    "follow",
    "fool",
    "force",
    "form",
    "found",
    "frame",
    "frighten",
    "fry",
    "gather",
    "gaze",
    "glow",
    "glue",
    "grab",
    "grate",
    "grease",
    "greet",
    "grin",
    "grip",
    "groan",
    "guarantee",
    "guard",
    "guess",
    "guide",
    "hammer",
    "hand",
    "handle",
    "hang",
    "happen",
    "harass",
    "harm",
    "hate",
    "haunt",
    "head",
    "heal",
    "heap",
    "heat",
    "help",
    "hook",
    "hop",
    "hope",
    "hover",
    "hug",
    "hum",
    "hunt",
    "hurry",
    "identify",
    "ignore",
    "imagine",
    "impress",
    "improve",
    "include",
    "increase",
    "influence",
    "inform",
    "inject",
    "injure",
    "instruct",
    "intend",
    "interest",
    "interfere",
    "interrupt",
    "introduce",
    "invent",
    "invite",
    "irritate",
    "itch",
    "jail",
    "jam",
    "jog",
    "join",
    "joke",
    "judge",
    "juggle",
    "jump",
    "kick",
    "kill",
    "kiss",
    "kneel",
    "knit",
    "knock",
    "knot",
    "label",
    "land",
    "last",
    "laugh",
    "launch",
    "learn",
    "level",
    "license",
    "lick",
    "lie",
    "lighten",
    "like",
    "list",
    "listen",
    "live",
    "load",
    "lock",
    "long",
    "look",
    "love",
    "man",
    "manage",
    "march",
    "mark",
    "marry",
    "match",
    "mate",
    "matter",
    "measure",
    "meddle",
    "melt",
    "memorise",
    "mend",
    "mess up",
    "milk",
    "mine",
    "miss",
    "mix",
    "moan",
    "moor",
    "mourn",
    "move",
    "muddle",
    "mug",
    "multiply",
    "murder",
    "nail",
    "name",
    "need",
    "nest",
    "nod",
    "note",
    "notice",
    "number",
    "obey",
    "object",
    "observe",
    "obtain",
    "occur",
    "offend",
    "offer",
    "open",
    "order",
    "overflow",
    "owe",
    "own",
    "pack",
    "paddle",
    "paint",
    "park",
    "part",
    "pass",
    "paste",
    "pat",
    "pause",
    "peck",
    "pedal",
    "peel",
    "peep",
    "perform",
    "permit",
    "phone",
    "pick",
    "pinch",
    "pine",
    "place",
    "plan",
    "plant",
    "play",
    "please",
    "plug",
    "point",
    "poke",
    "polish",
    "pop",
    "possess",
    "post",
    "pour",
    "practise",
    "pray",
    "preach",
    "precede",
    "prefer",
    "prepare",
    "present",
    "preserve",
    "press",
    "pretend",
    "prevent",
    "prick",
    "print",
    "produce",
    "program",
    "promise",
    "protect",
    "provide",
    "pull",
    "pump",
    "punch",
    "puncture",
    "punish",
    "push",
    "question",
    "queue",
    "race",
    "radiate",
    "rain",
    "raise",
    "reach",
    "realise",
    "receive",
    "recognise",
    "record",
    "reduce",
    "reflect",
    "refuse",
    "regret",
    "reign",
    "reject",
    "rejoice",
    "relax",
    "release",
    "rely",
    "remain",
    "remember",
    "remind",
    "remove",
    "repair",
    "repeat",
    "replace",
    "reply",
    "report",
    "reproduce",
    "request",
    "rescue",
    "retire",
    "return",
    "rhyme",
    "rinse",
    "risk",
    "rob",
    "rock",
    "roll",
    "rot",
    "rub",
    "ruin",
    "rule",
    "rush",
    "sack",
    "sail",
    "satisfy",
    "save",
    "saw",
    "scare",
    "scatter",
    "scold",
    "scorch",
    "scrape",
    "scratch",
    "scream",
    "screw",
    "scribble",
    "scrub",
    "seal",
    "search",
    "separate",
    "serve",
    "settle",
    "shade",
    "share",
    "shave",
    "shelter",
    "shiver",
    "shock",
    "shop",
    "shrug",
    "sigh",
    "sign",
    "signal",
    "sin",
    "sip",
    "ski",
    "skip",
    "slap",
    "slip",
    "slow",
    "smash",
    "smell",
    "smile",
    "smoke",
    "snatch",
    "sneeze",
    "sniff",
    "snore",
    "snow",
    "soak",
    "soothe",
    "sound",
    "spare",
    "spark",
    "sparkle",
    "spell",
    "spill",
    "spoil",
    "spot",
    "spray",
    "sprout",
    "squash",
    "squeak",
    "squeal",
    "squeeze",
    "stain",
    "stamp",
    "stare",
    "start",
    "stay",
    "steer",
    "step",
    "stir",
    "stitch",
    "stop",
    "store",
    "strap",
    "strengthen",
    "stretch",
    "strip",
    "stroke",
    "stuff",
    "subtract",
    "succeed",
    "suck",
    "suffer",
    "suggest",
    "suit",
    "supply",
    "support",
    "suppose",
    "surprise",
    "surround",
    "suspect",
    "suspend",
    "switch",
    "talk",
    "tame",
    "tap",
    "taste",
    "tease",
    "telephone",
    "tempt",
    "terrify",
    "test",
    "thank",
    "thaw",
    "tick",
    "tickle",
    "tie",
    "time",
    "tip",
    "tire",
    "touch",
    "tour",
    "tow",
    "trace",
    "trade",
    "train",
    "transport",
    "trap",
    "travel",
    "treat",
    "tremble",
    "trick",
    "trip",
    "trot",
    "trouble",
    "trust",
    "try",
    "tug",
    "tumble",
    "turn",
    "twist",
    "type",
    "undress",
    "unfasten",
    "unite",
    "unlock",
    "unpack",
    "untidy",
    "use",
    "vanish",
    "visit",
    "wail",
    "wait",
    "walk",
    "wander",
    "want",
    "warm",
    "warn",
    "wash",
    "waste",
    "watch",
    "water",
    "wave",
    "weigh",
    "welcome",
    "whine",
    "whip",
    "whirl",
    "whisper",
    "whistle",
    "wink",
    "wipe",
    "wish",
    "wobble",
    "wonder",
    "work",
    "worry",
    "wrap",
    "wreck",
    "wrestle",
    "wriggle",
    "x-ray",
    "yawn",
    "yell",
    "zip",
    "zoom"
  ]

let colors = [
  {
      "hex": "#EFDECD", 
      "name": "Almond", 
      "rgb": "(239, 222, 205)"
  }, 
  {
      "hex": "#CD9575", 
      "name": "Antique Brass", 
      "rgb": "(205, 149, 117)"
  }, 
  {
      "hex": "#FDD9B5", 
      "name": "Apricot", 
      "rgb": "(253, 217, 181)"
  }, 
  {
      "hex": "#78DBE2", 
      "name": "Aquamarine", 
      "rgb": "(120, 219, 226)"
  }, 
  {
      "hex": "#87A96B", 
      "name": "Asparagus", 
      "rgb": "(135, 169, 107)"
  }, 
  {
      "hex": "#FFA474", 
      "name": "Atomic Tangerine", 
      "rgb": "(255, 164, 116)"
  }, 
  {
      "hex": "#FAE7B5", 
      "name": "Banana Mania", 
      "rgb": "(250, 231, 181)"
  }, 
  {
      "hex": "#9F8170", 
      "name": "Beaver", 
      "rgb": "(159, 129, 112)"
  }, 
  {
      "hex": "#FD7C6E", 
      "name": "Bittersweet", 
      "rgb": "(253, 124, 110)"
  }, 
  {
      "hex": "#000000", 
      "name": "Black", 
      "rgb": "(0,0,0)"
  }, 
  {
      "hex": "#ACE5EE", 
      "name": "Blizzard Blue", 
      "rgb": "(172, 229, 238)"
  }, 
  {
      "hex": "#1F75FE", 
      "name": "Blue", 
      "rgb": "(31, 117, 254)"
  }, 
  {
      "hex": "#A2A2D0", 
      "name": "Blue Bell", 
      "rgb": "(162, 162, 208)"
  }, 
  {
      "hex": "#6699CC", 
      "name": "Blue Gray", 
      "rgb": "(102, 153, 204)"
  }, 
  {
      "hex": "#0D98BA", 
      "name": "Blue Green", 
      "rgb": "(13, 152, 186)"
  }, 
  {
      "hex": "#7366BD", 
      "name": "Blue Violet", 
      "rgb": "(115, 102, 189)"
  }, 
  {
      "hex": "#DE5D83", 
      "name": "Blush", 
      "rgb": "(222, 93, 131)"
  }, 
  {
      "hex": "#CB4154", 
      "name": "Brick Red", 
      "rgb": "(203, 65, 84)"
  }, 
  {
      "hex": "#B4674D", 
      "name": "Brown", 
      "rgb": "(180, 103, 77)"
  }, 
  {
      "hex": "#FF7F49", 
      "name": "Burnt Orange", 
      "rgb": "(255, 127, 73)"
  }, 
  {
      "hex": "#EA7E5D", 
      "name": "Burnt Sienna", 
      "rgb": "(234, 126, 93)"
  }, 
  {
      "hex": "#B0B7C6", 
      "name": "Cadet Blue", 
      "rgb": "(176, 183, 198)"
  }, 
  {
      "hex": "#FFFF99", 
      "name": "Canary", 
      "rgb": "(255, 255, 153)"
  }, 
  {
      "hex": "#1CD3A2", 
      "name": "Caribbean Green", 
      "rgb": "(28, 211, 162)"
  }, 
  {
      "hex": "#FFAACC", 
      "name": "Carnation Pink", 
      "rgb": "(255, 170, 204)"
  }, 
  {
      "hex": "#DD4492", 
      "name": "Cerise", 
      "rgb": "(221, 68, 146)"
  }, 
  {
      "hex": "#1DACD6", 
      "name": "Cerulean", 
      "rgb": "(29, 172, 214)"
  }, 
  {
      "hex": "#BC5D58", 
      "name": "Chestnut", 
      "rgb": "(188, 93, 88)"
  }, 
  {
      "hex": "#DD9475", 
      "name": "Copper", 
      "rgb": "(221, 148, 117)"
  }, 
  {
      "hex": "#9ACEEB", 
      "name": "Cornflower", 
      "rgb": "(154, 206, 235)"
  }, 
  {
      "hex": "#FFBCD9", 
      "name": "Cotton Candy", 
      "rgb": "(255, 188, 217)"
  }, 
  {
      "hex": "#FDDB6D", 
      "name": "Dandelion", 
      "rgb": "(253, 219, 109)"
  }, 
  {
      "hex": "#2B6CC4", 
      "name": "Denim", 
      "rgb": "(43, 108, 196)"
  }, 
  {
      "hex": "#EFCDB8", 
      "name": "Desert Sand", 
      "rgb": "(239, 205, 184)"
  }, 
  {
      "hex": "#6E5160", 
      "name": "Eggplant", 
      "rgb": "(110, 81, 96)"
  }, 
  {
      "hex": "#CEFF1D", 
      "name": "Electric Lime", 
      "rgb": "(206, 255, 29)"
  }, 
  {
      "hex": "#71BC78", 
      "name": "Fern", 
      "rgb": "(113, 188, 120)"
  }, 
  {
      "hex": "#6DAE81", 
      "name": "Forest Green", 
      "rgb": "(109, 174, 129)"
  }, 
  {
      "hex": "#C364C5", 
      "name": "Fuchsia", 
      "rgb": "(195, 100, 197)"
  }, 
  {
      "hex": "#CC6666", 
      "name": "Fuzzy Wuzzy", 
      "rgb": "(204, 102, 102)"
  }, 
  {
      "hex": "#E7C697", 
      "name": "Gold", 
      "rgb": "(231, 198, 151)"
  }, 
  {
      "hex": "#FCD975", 
      "name": "Goldenrod", 
      "rgb": "(252, 217, 117)"
  }, 
  {
      "hex": "#A8E4A0", 
      "name": "Granny Smith Apple", 
      "rgb": "(168, 228, 160)"
  }, 
  {
      "hex": "#95918C", 
      "name": "Gray", 
      "rgb": "(149, 145, 140)"
  }, 
  {
      "hex": "#1CAC78", 
      "name": "Green", 
      "rgb": "(28, 172, 120)"
  }, 
  {
      "hex": "#1164B4", 
      "name": "Green Blue", 
      "rgb": "(17, 100, 180)"
  }, 
  {
      "hex": "#F0E891", 
      "name": "Green Yellow", 
      "rgb": "(240, 232, 145)"
  }, 
  {
      "hex": "#FF1DCE", 
      "name": "Hot Magenta", 
      "rgb": "(255, 29, 206)"
  }, 
  {
      "hex": "#B2EC5D", 
      "name": "Inchworm", 
      "rgb": "(178, 236, 93)"
  }, 
  {
      "hex": "#5D76CB", 
      "name": "Indigo", 
      "rgb": "(93, 118, 203)"
  }, 
  {
      "hex": "#CA3767", 
      "name": "Jazzberry Jam", 
      "rgb": "(202, 55, 103)"
  }, 
  {
      "hex": "#3BB08F", 
      "name": "Jungle Green", 
      "rgb": "(59, 176, 143)"
  }, 
  {
      "hex": "#FEFE22", 
      "name": "Laser Lemon", 
      "rgb": "(254, 254, 34)"
  }, 
  {
      "hex": "#FCB4D5", 
      "name": "Lavender", 
      "rgb": "(252, 180, 213)"
  }, 
  {
      "hex": "#FFF44F", 
      "name": "Lemon Yellow", 
      "rgb": "(255, 244, 79)"
  }, 
  {
      "hex": "#FFBD88", 
      "name": "Macaroni and Cheese", 
      "rgb": "(255, 189, 136)"
  }, 
  {
      "hex": "#F664AF", 
      "name": "Magenta", 
      "rgb": "(246, 100, 175)"
  }, 
  {
      "hex": "#AAF0D1", 
      "name": "Magic Mint", 
      "rgb": "(170, 240, 209)"
  }, 
  {
      "hex": "#CD4A4C", 
      "name": "Mahogany", 
      "rgb": "(205, 74, 76)"
  }, 
  {
      "hex": "#EDD19C", 
      "name": "Maize", 
      "rgb": "(237, 209, 156)"
  }, 
  {
      "hex": "#979AAA", 
      "name": "Manatee", 
      "rgb": "(151, 154, 170)"
  }, 
  {
      "hex": "#FF8243", 
      "name": "Mango Tango", 
      "rgb": "(255, 130, 67)"
  }, 
  {
      "hex": "#C8385A", 
      "name": "Maroon", 
      "rgb": "(200, 56, 90)"
  }, 
  {
      "hex": "#EF98AA", 
      "name": "Mauvelous", 
      "rgb": "(239, 152, 170)"
  }, 
  {
      "hex": "#FDBCB4", 
      "name": "Melon", 
      "rgb": "(253, 188, 180)"
  }, 
  {
      "hex": "#1A4876", 
      "name": "Midnight Blue", 
      "rgb": "(26, 72, 118)"
  }, 
  {
      "hex": "#30BA8F", 
      "name": "Mountain Meadow", 
      "rgb": "(48, 186, 143)"
  }, 
  {
      "hex": "#C54B8C", 
      "name": "Mulberry", 
      "rgb": "(197, 75, 140)"
  }, 
  {
      "hex": "#1974D2", 
      "name": "Navy Blue", 
      "rgb": "(25, 116, 210)"
  }, 
  {
      "hex": "#FFA343", 
      "name": "Neon Carrot", 
      "rgb": "(255, 163, 67)"
  }, 
  {
      "hex": "#BAB86C", 
      "name": "Olive Green", 
      "rgb": "(186, 184, 108)"
  }, 
  {
      "hex": "#FF7538", 
      "name": "Orange", 
      "rgb": "(255, 117, 56)"
  }, 
  {
      "hex": "#FF2B2B", 
      "name": "Orange Red", 
      "rgb": "(255, 43, 43)"
  }, 
  {
      "hex": "#F8D568", 
      "name": "Orange Yellow", 
      "rgb": "(248, 213, 104)"
  }, 
  {
      "hex": "#E6A8D7", 
      "name": "Orchid", 
      "rgb": "(230, 168, 215)"
  }, 
  {
      "hex": "#414A4C", 
      "name": "Outer Space", 
      "rgb": "(65, 74, 76)"
  }, 
  {
      "hex": "#FF6E4A", 
      "name": "Outrageous Orange", 
      "rgb": "(255, 110, 74)"
  }, 
  {
      "hex": "#1CA9C9", 
      "name": "Pacific Blue", 
      "rgb": "(28, 169, 201)"
  }, 
  {
      "hex": "#FFCFAB", 
      "name": "Peach", 
      "rgb": "(255, 207, 171)"
  }, 
  {
      "hex": "#C5D0E6", 
      "name": "Periwinkle", 
      "rgb": "(197, 208, 230)"
  }, 
  {
      "hex": "#FDDDE6", 
      "name": "Piggy Pink", 
      "rgb": "(253, 221, 230)"
  }, 
  {
      "hex": "#158078", 
      "name": "Pine Green", 
      "rgb": "(21, 128, 120)"
  }, 
  {
      "hex": "#FC74FD", 
      "name": "Pink Flamingo", 
      "rgb": "(252, 116, 253)"
  }, 
  {
      "hex": "#F78FA7", 
      "name": "Pink Sherbet", 
      "rgb": "(247, 143, 167)"
  }, 
  {
      "hex": "#8E4585", 
      "name": "Plum", 
      "rgb": "(142, 69, 133)"
  }, 
  {
      "hex": "#7442C8", 
      "name": "Purple Heart", 
      "rgb": "(116, 66, 200)"
  }, 
  {
      "hex": "#9D81BA", 
      "name": "Purple Mountain's Majesty", 
      "rgb": "(157, 129, 186)"
  }, 
  {
      "hex": "#FE4EDA", 
      "name": "Purple Pizzazz", 
      "rgb": "(254, 78, 218)"
  }, 
  {
      "hex": "#FF496C", 
      "name": "Radical Red", 
      "rgb": "(255, 73, 108)"
  }, 
  {
      "hex": "#D68A59", 
      "name": "Raw Sienna", 
      "rgb": "(214, 138, 89)"
  }, 
  {
      "hex": "#714B23", 
      "name": "Raw Umber", 
      "rgb": "(113, 75, 35)"
  }, 
  {
      "hex": "#FF48D0", 
      "name": "Razzle Dazzle Rose", 
      "rgb": "(255, 72, 208)"
  }, 
  {
      "hex": "#E3256B", 
      "name": "Razzmatazz", 
      "rgb": "(227, 37, 107)"
  }, 
  {
      "hex": "#EE204D", 
      "name": "Red", 
      "rgb": "(238,32 ,77 )"
  }, 
  {
      "hex": "#FF5349", 
      "name": "Red Orange", 
      "rgb": "(255, 83, 73)"
  }, 
  {
      "hex": "#C0448F", 
      "name": "Red Violet", 
      "rgb": "(192, 68, 143)"
  }, 
  {
      "hex": "#1FCECB", 
      "name": "Robin's Egg Blue", 
      "rgb": "(31, 206, 203)"
  }, 
  {
      "hex": "#7851A9", 
      "name": "Royal Purple", 
      "rgb": "(120, 81, 169)"
  }, 
  {
      "hex": "#FF9BAA", 
      "name": "Salmon", 
      "rgb": "(255, 155, 170)"
  }, 
  {
      "hex": "#FC2847", 
      "name": "Scarlet", 
      "rgb": "(252, 40, 71)"
  }, 
  {
      "hex": "#76FF7A", 
      "name": "Screamin' Green", 
      "rgb": "(118, 255, 122)"
  }, 
  {
      "hex": "#9FE2BF", 
      "name": "Sea Green", 
      "rgb": "(159, 226, 191)"
  }, 
  {
      "hex": "#A5694F", 
      "name": "Sepia", 
      "rgb": "(165, 105, 79)"
  }, 
  {
      "hex": "#8A795D", 
      "name": "Shadow", 
      "rgb": "(138, 121, 93)"
  }, 
  {
      "hex": "#45CEA2", 
      "name": "Shamrock", 
      "rgb": "(69, 206, 162)"
  }, 
  {
      "hex": "#FB7EFD", 
      "name": "Shocking Pink", 
      "rgb": "(251, 126, 253)"
  }, 
  {
      "hex": "#CDC5C2", 
      "name": "Silver", 
      "rgb": "(205, 197, 194)"
  }, 
  {
      "hex": "#80DAEB", 
      "name": "Sky Blue", 
      "rgb": "(128, 218, 235)"
  }, 
  {
      "hex": "#ECEABE", 
      "name": "Spring Green", 
      "rgb": "(236, 234, 190)"
  }, 
  {
      "hex": "#FFCF48", 
      "name": "Sunglow", 
      "rgb": "(255, 207, 72)"
  }, 
  {
      "hex": "#FD5E53", 
      "name": "Sunset Orange", 
      "rgb": "(253, 94, 83)"
  }, 
  {
      "hex": "#FAA76C", 
      "name": "Tan", 
      "rgb": "(250, 167, 108)"
  }, 
  {
      "hex": "#18A7B5", 
      "name": "Teal Blue", 
      "rgb": "(24, 167, 181)"
  }, 
  {
      "hex": "#EBC7DF", 
      "name": "Thistle", 
      "rgb": "(235, 199, 223)"
  }, 
  {
      "hex": "#FC89AC", 
      "name": "Tickle Me Pink", 
      "rgb": "(252, 137, 172)"
  }, 
  {
      "hex": "#DBD7D2", 
      "name": "Timberwolf", 
      "rgb": "(219, 215, 210)"
  }, 
  {
      "hex": "#17806D", 
      "name": "Tropical Rain Forest", 
      "rgb": "(23, 128, 109)"
  }, 
  {
      "hex": "#DEAA88", 
      "name": "Tumbleweed", 
      "rgb": "(222, 170, 136)"
  }, 
  {
      "hex": "#77DDE7", 
      "name": "Turquoise Blue", 
      "rgb": "(119, 221, 231)"
  }, 
  {
      "hex": "#FFFF66", 
      "name": "Unmellow Yellow", 
      "rgb": "(255, 255, 102)"
  }, 
  {
      "hex": "#926EAE", 
      "name": "Violet (Purple)", 
      "rgb": "(146, 110, 174)"
  }, 
  {
      "hex": "#324AB2", 
      "name": "Violet Blue", 
      "rgb": "(50, 74, 178)"
  }, 
  {
      "hex": "#F75394", 
      "name": "Violet Red", 
      "rgb": "(247, 83, 148)"
  }, 
  {
      "hex": "#FFA089", 
      "name": "Vivid Tangerine", 
      "rgb": "(255, 160, 137)"
  }, 
  {
      "hex": "#8F509D", 
      "name": "Vivid Violet", 
      "rgb": "(143, 80, 157)"
  }, 
  {
      "hex": "#FFFFFF", 
      "name": "White", 
      "rgb": "(255, 255, 255)"
  }, 
  {
      "hex": "#A2ADD0", 
      "name": "Wild Blue Yonder", 
      "rgb": "(162, 173, 208)"
  }, 
  {
      "hex": "#FF43A4", 
      "name": "Wild Strawberry", 
      "rgb": "(255, 67, 164)"
  }, 
  {
      "hex": "#FC6C85", 
      "name": "Wild Watermelon", 
      "rgb": "(252, 108, 133)"
  }, 
  {
      "hex": "#CDA4DE", 
      "name": "Wisteria", 
      "rgb": "(205, 164, 222)"
  }, 
  {
      "hex": "#FCE883", 
      "name": "Yellow", 
      "rgb": "(252, 232, 131)"
  }, 
  {
      "hex": "#C5E384", 
      "name": "Yellow Green", 
      "rgb": "(197, 227, 132)"
  }, 
  {
      "hex": "#FFAE42", 
      "name": "Yellow Orange", 
      "rgb": "(255, 174, 66)"
  }
]